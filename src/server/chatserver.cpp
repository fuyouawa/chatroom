#include <coroutine>
#include "ioservice_pool.h"
#include "chatserver.h"
#include "chatservice.h"
#include "tools/logger.h"

namespace chatroom
{
ChatServer::ChatServer(IOService& ios, uint16_t port)
    : acceptor_{ios, {boost::asio::ip::tcp::v4(), port}}
{
}

void ChatServer::Start() {
    boost::asio::co_spawn(acceptor_.get_executor(), [this]()->boost::asio::awaitable<void>{ 
        CHATROOM_LOG_INFO("Start accept!");
        while (true) {
            try
            {
                auto& ios = IOServicePool::instance().NextIOService();
                auto socket = co_await acceptor_.async_accept(ios, boost::asio::use_awaitable);

                auto session = std::make_shared<ChatSession>(std::move(socket), this);
                {
                    std::lock_guard<std::mutex> lock{mutex_};
                    sessions_.insert({session->uuid(), session});
                }
                HandleNewSession(session);
            }
            catch(const boost::system::system_error& e)
            {
                CHATROOM_LOG_ERROR("Session accept failed: {}", e.what());
            }
        }
    }, boost::asio::detached);
}

void ChatServer::RemoveSession(const std::string& uuid) {
    std::lock_guard<std::mutex> lock{mutex_};
    sessions_.erase(uuid);
}

void ChatServer::HandleNewSession(ChatSessionPtr session) {
    CHATROOM_LOG_INFO("New connection from {}", session->socket().remote_endpoint());
    session->set_close_callback([](auto session) {
        CHATROOM_LOG_INFO("session({}) closed connection!", session->socket().remote_endpoint());
        session->Close();
    });
    session->set_read_callback([](auto session, auto& packet) {
        ChatService::instance().HandleRecvPacket(session, packet);
    });
    session->Start();
}
}
