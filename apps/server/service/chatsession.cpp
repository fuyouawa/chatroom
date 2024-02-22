#include "chatsession.h"
#include <coroutine>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "tools/logger.h"
#include "common/core/packet.h"
#include "service/chatserver.h"
#include "service/chatservice.h"

namespace chatroom
{
void HandleSessionError(ChatSessionPtr session, const std::exception& e) {
    CHATROOM_LOG_ERROR("Error occur in {}: {}", session->name(), e.what());
    session->Close();
}

ChatSession::ChatSession(Socket&& socket, ChatServer* server, std::string_view name)
    : logging_{false},
    name_{name},
    account_{0},
    is_closed_{false},
    socket_{std::move(socket)},
    server_{server},
    uuid_{boost::uuids::to_string(boost::uuids::random_generator()())}
{
}

ChatSession::~ChatSession() noexcept {
    Close();
}

void ChatSession::Close() noexcept {
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
        CHATROOM_LOG_ERROR("Error occur when {} closing: {}", name(), e.what());
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
                Close();
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

void ChatSession::Send(MessageID msgid, const google::protobuf::Message& data, bool is_emergency) noexcept {
    try
    {
        if (is_closed()) {
            CHATROOM_LOG_WARNING("Try to send a closed session!");
            return;
        }
        const auto send_packet = std::make_shared<SendPacket>(msgid, data);
        std::unique_lock<std::mutex> lock{mutex_};
        const auto old_deque_size = send_deque_.size();
        if (old_deque_size >= kMaxSendQueue) {
            CHATROOM_LOG_ERROR("Send message's queue fulled!");
            Close();
            //TODO: 高水位处理
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
        const auto packet = send_deque_.front();
        lock.unlock();

        boost::asio::async_write(socket_,
            boost::asio::buffer(packet->Pack()),
            [self=shared_from_this()](auto ec, auto){ self->HandleWrited(ec); });
    }
    catch(const std::exception& e)
    {
        CHATROOM_LOG_ERROR("Error occur when sending data to {}:", name(), e.what());
    }
}

void ChatSession::Send(MessageID msgid, const google::protobuf::Message& data) noexcept {
    Send(msgid, data, false);
}

void ChatSession::SendEmergency(MessageID msgid, const google::protobuf::Message& data) noexcept {
    Send(msgid, data, true);
}


void ChatSession::HandleWrited(const boost::system::error_code& ec) {
    try
    {
        if (!ec) {
            std::unique_lock<std::mutex> lock{mutex_};
            send_deque_.pop_front();
            if (!send_deque_.empty()) {
                const auto packet = send_deque_.front();
                lock.unlock();

                boost::asio::async_write(socket_,
                    boost::asio::buffer(packet->Pack()),
                    [self=shared_from_this()](auto ec, auto){ self->HandleWrited(ec); });
            }
        }
        else {
            CHATROOM_LOG_ERROR("{} write message failed: {}", name(), ec.message());
            Close();
        }
    }
    catch(const std::exception& e)
    {
        HandleSessionError(shared_from_this(), e);
    }
}
}
