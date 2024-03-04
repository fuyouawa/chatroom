#include "service/chatsession.h"
#include <coroutine>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "tools/logger.h"
#include "common/core/packet.h"
#include "service/chatserver.h"
#include "service/chatservice.h"

namespace chatroom {
void HandleSessionError(ChatSessionPtr session, const std::exception& e) {
    CHATROOM_LOG_ERROR("Error occur in {}: {}", session->client_ep(), e.what());
    session->Close();
}

ChatSession::ChatSession(Socket&& socket, ChatServer* server)
    : logging_{false},
    user_id_{0},
    is_closed_{false},
    socket_{std::move(socket)},
    server_{server},
    uuid_{boost::uuids::to_string(boost::uuids::random_generator()())}
{
}

ChatSession::~ChatSession() {
    Close();
}

void ChatSession::Close() {
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
        CHATROOM_LOG_ERROR("Error occur when {} close one session: {}", client_ep(), e.what());
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

void ChatSession::Send(uint16_t msgid, const google::protobuf::Message& data) {
    try
    {
        if (is_closed()) {
            CHATROOM_LOG_WARNING("Try to send a closed session!");
            return;
        }
        std::unique_lock<std::mutex> lock{mutex_};
        const auto old_queue_size = send_queue_.size();
        if (old_queue_size >= kMaxSendQueue) {
            CHATROOM_LOG_ERROR("Send message's queue fulled!");
            Close();
            //TODO: 高水位处理
            return;
        }
        send_queue_.emplace(msgid, data);
        if (old_queue_size > 0) {
            return;
        }
        const auto& packet = send_queue_.front();
        lock.unlock();

        boost::asio::async_write(socket_,
            boost::asio::buffer(packet.Pack()),
            [self=shared_from_this()](auto ec, auto){ self->HandleWrited(ec); });
    }
    catch(const std::exception& e)
    {
        CHATROOM_LOG_ERROR("Error occur when sending data to {}:{}", client_ep(), e.what());
    }
}


void ChatSession::HandleWrited(const boost::system::error_code& ec) {
    try
    {
        if (!ec) {
            std::unique_lock<std::mutex> lock{mutex_};
            send_queue_.pop();
            if (!send_queue_.empty()) {
                const auto& packet = send_queue_.front();
                lock.unlock();

                boost::asio::async_write(socket_,
                    boost::asio::buffer(packet.Pack()),
                    [self=shared_from_this()](auto ec, auto){ self->HandleWrited(ec); });
            }
        }
        else {
            CHATROOM_LOG_ERROR("Write message to {} failed: {}", client_ep(), ec.message());
            Close();
        }
    }
    catch(const std::exception& e)
    {
        HandleSessionError(shared_from_this(), e);
    }
}
}   // namespace chatroom
