#include "chatsession.h"
#include <coroutine>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "tools/logger.h"
#include "tools/packet.h"
#include "server/chatserver.h"

namespace chatroom
{
void HandleSessionError(ChatSessionPtr session, const std::exception& e) {
    CHATROOM_LOG_ERROR("error occur in session({}): {}", session->socket().remote_endpoint(), e.what());
    session->Close();
}

ChatSession::ChatSession(Socket&& socket, ChatServer* server)
    : is_closed_{false},
    socket_{std::move(socket)},
    server_{server},
    uuid_{boost::uuids::to_string(boost::uuids::random_generator()())}
{
}

void ChatSession::Close() {
    socket_.close();
    is_closed_ = true;
    server_->RemoveSession(uuid_);
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
                assert(n == sizeof(network_header));
                RecvPacket recv_packet{network_header};

                n = co_await boost::asio::async_read(
                    socket_,
                    boost::asio::buffer(recv_packet.data_buf()),
                    boost::asio::use_awaitable);
                assert(n == recv_packet.data_size());

                if (read_callback_)
                    read_callback_(self, std::move(recv_packet));
            }
            co_return;
        }
        catch(const boost::system::system_error& e) {
            if (e.code() == boost::asio::error::eof) {
                if (close_callback_)
                    close_callback_(self);
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

void ChatSession::Send(uint16_t msg_type, std::span<char> data) {
    std::unique_lock<std::mutex> lock{mutex_};
    auto old_queue_size = send_queue_.size();
    if (old_queue_size >= kMaxSendQueue) {
        CHATROOM_LOG_ERROR("send message's queue fulled!");
        Close();
        return;
    }
    auto packet = std::make_shared<SendPacket>(msg_type, data);
    if (old_queue_size > 0) {
        send_queue_.push(packet);
        return;
    }
    lock.unlock();

    boost::asio::async_write(socket_,
        boost::asio::buffer(packet->packed_buf()),
        [self=shared_from_this()](auto ec, auto){ self->HandleWrited(ec); });
}


void ChatSession::HandleWrited(const boost::system::error_code& ec) {
    try
    {
        if (!ec) {
            std::unique_lock<std::mutex> lock{mutex_};
            if (!send_queue_.empty()) {
                auto packet = send_queue_.front();
                send_queue_.pop();
                lock.unlock();

                boost::asio::async_write(socket_,
                    boost::asio::buffer(packet->packed_buf()),
                    [self=shared_from_this()](auto ec, auto){ self->HandleWrited(ec); });
            }
        }
        else {
            CHATROOM_LOG_ERROR("session write message failed: {}", ec.message());
            Close();
        }
    }
    catch(const std::exception& e)
    {
        HandleSessionError(shared_from_this(), e);
    }
}
}
