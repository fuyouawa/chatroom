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
void HandleSessionEofError(ChatSessionPtr session) {
    CHATROOM_LOG_INFO("session({}) closed connection!", session->socket().remote_endpoint());
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
    server_->RemoveSession(uuid_);
    is_closed_ = true;
}

void ChatSession::Start() {
    boost::asio::co_spawn(socket_.get_executor(), [self = shared_from_this()]()->boost::asio::awaitable<void>{
        try
        {
            PacketHeader network_header;
            while (!self->is_closed_) {
                co_await boost::asio::async_read(
                    self->socket_,
                    boost::asio::buffer(&network_header, sizeof(network_header)),
                    boost::asio::use_awaitable);
                RecvPacket recv_packet{network_header};

                co_await boost::asio::async_read(
                    self->socket_,
                    boost::asio::buffer(recv_packet.data_buf()),
                    boost::asio::use_awaitable);
                //TODO
            }
            co_return;
        }
        catch(const boost::system::system_error& e) {
            if (e.code() == boost::asio::error::eof) {
                HandleSessionEofError(self);
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

}
}
