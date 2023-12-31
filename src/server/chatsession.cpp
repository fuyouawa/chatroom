#include "chatsession.h"
#include <coroutine>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "tools/logger.h"
#include "tools/packet.h"
#include "server/chatserver.h"
#include "server/chatservice.h"
#include "message/emergency.pb.h"
#include "public.h"

namespace chatroom
{
void HandleSessionError(ChatSessionPtr session, const std::exception& e) {
    CHATROOM_LOG_ERROR("Error occur in session({}): {}", session->socket().remote_endpoint(), e.what());
    session->Terminate();
}

ChatSession::ChatSession(Socket&& socket, ChatServer* server)
    : is_closed_{false},
    socket_{std::move(socket)},
    server_{server},
    uuid_{boost::uuids::to_string(boost::uuids::random_generator()())}
{
}

ChatSession::~ChatSession() noexcept {
    Terminate();
}

void ChatSession::Terminate() noexcept {
    try
    {
        bool expect = false;
        if (is_closed_.compare_exchange_strong(expect, true)) {
            if (close_callback_)
                close_callback_(shared_from_this());
            server_->RemoveSession(uuid_);
            socket_.close();
        }
    }
    catch(const std::exception& e)
    {
        CHATROOM_LOG_ERROR("Error occur when session({}) closing: {}", socket_.remote_endpoint(), e.what());
    }
    
}

void ChatSession::Start() {
    boost::asio::co_spawn(socket_.get_executor(), [self = shared_from_this(), this]()->boost::asio::awaitable<void>{
        try
        {
            PacketHeader network_header;
            while (!is_closed_) {
                auto n = co_await boost::asio::async_read(
                    socket_,
                    boost::asio::buffer(&network_header, sizeof(network_header)),
                    boost::asio::use_awaitable);
                if (n == 0)
                    throw boost::system::system_error(boost::asio::error::eof);
                assert(n == sizeof(network_header));
                RecvPacket recv_packet{network_header};

                n = co_await boost::asio::async_read(
                    socket_,
                    boost::asio::buffer(recv_packet.data(), recv_packet.data_size()),
                    boost::asio::use_awaitable);
                if (n == 0)
                    throw boost::system::system_error(boost::asio::error::eof);
                assert(n == recv_packet.data_size());

                if (read_callback_)
                    read_callback_(self, recv_packet);
            }
            co_return;
        }
        catch(const boost::system::system_error& e) {
            if (e.code() == boost::asio::error::eof) {
                Terminate();
            }
            else {
                HandleSessionError(self, e);
            }
        }
        catch(const std::exception& e) {
            HandleSessionError(self, e);
        }
    }, boost::asio::detached);
}

void ChatSession::Send(uint16_t msg_type, const google::protobuf::Message& data) {
    Send(msg_type, data, false);
}

void ChatSession::SendEmergency(int event_id, std::string_view extras) {
    message::Emergency emergency;
    emergency.set_event_id(event_id);
    emergency.set_extras(extras.data(), extras.size());
    Send(kEmergencyMsg, emergency, true);
}

void ChatSession::Send(uint16_t msg_type, const google::protobuf::Message& data, bool is_emergency) {
    if (is_closed()) {
        CHATROOM_LOG_WARNING("Try to send a closed session!");
        return;
    }
    auto send_packet = std::make_shared<SendPacket>(msg_type, data);
    std::unique_lock<std::mutex> lock{mutex_};
    auto old_deque_size = send_deque_.size();
    if (old_deque_size >= kMaxSendQueue) {
        CHATROOM_LOG_ERROR("Send message's queue fulled!");
        Terminate();
        return;
    }
    if (is_emergency) {
        if (old_deque_size <= 1) {
            send_deque_.push_back(send_packet);
        }
        else {
            send_deque_.insert(send_deque_.begin() + 1, send_packet);
        }
    }
    else {
        send_deque_.push_back(send_packet);
    }
    if (old_deque_size > 0) {
        return;
    }
    auto packet = send_deque_.front();
    lock.unlock();

    boost::asio::async_write(socket_,
        boost::asio::buffer(packet->Pack()),
        [self=shared_from_this()](auto ec, auto){ self->HandleWrited(ec); });
}


void ChatSession::HandleWrited(const boost::system::error_code& ec) {
    try
    {
        if (!ec) {
            std::unique_lock<std::mutex> lock{mutex_};
            send_deque_.pop_front();
            if (!send_deque_.empty()) {
                auto packet = send_deque_.front();
                lock.unlock();

                boost::asio::async_write(socket_,
                    boost::asio::buffer(packet->Pack()),
                    [self=shared_from_this()](auto ec, auto){ self->HandleWrited(ec); });
            }
        }
        else {
            CHATROOM_LOG_ERROR("Session write message failed: {}", ec.message());
            Terminate();
        }
    }
    catch(const std::exception& e)
    {
        HandleSessionError(shared_from_this(), e);
    }
}
}
