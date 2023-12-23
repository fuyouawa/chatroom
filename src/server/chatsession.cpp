#include "chatsession.h"
#include <coroutine>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "tools/logger.h"
#include "tools/packet.h"
#include "server/chatserver.h"

namespace chatroom
{
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
            Packet::Header packet_header;
            while (!self->is_closed_) {
                co_await boost::asio::async_read(
                    self->socket_,
                    boost::asio::buffer(&packet_header, sizeof(packet_header)),
                    boost::asio::use_awaitable);
                self->recv_packet_->FromNetworkHeader(packet_header);

                self->recv_packet_->Clear();
                co_await boost::asio::async_read(
                    self->socket_,
                    boost::asio::buffer(self->recv_packet_->data(), self->recv_packet_->data_size()),
                    boost::asio::use_awaitable);
            }
            co_return;
        }
        catch(const boost::system::system_error& e) {
            if (e.code() == boost::asio::error::eof) {
                CHATROOM_LOG_INFO("session({}) closed connection!", self->socket_.remote_endpoint());
                self->Close();
            }
            else {
                CHATROOM_LOG_ERROR("error occur in session({}): {}", self->socket_.remote_endpoint(), e.what());
                self->Close();
            }
        }
        catch(const std::exception& e) {
            CHATROOM_LOG_ERROR("error occur in session({}): {}", self->socket_.remote_endpoint(), e.what());
            self->Close();
        }
    }, boost::asio::detached);
}
}
