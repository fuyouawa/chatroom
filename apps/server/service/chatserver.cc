#include "chatserver.h"
#include <coroutine>
#include "service/chatservice.h"
#include "tools/ioservice_pool.h"
#include "tools/logger.h"
#include "common/tools/format.h"

namespace chatroom
{
ChatServer::ChatServer(boost::asio::io_service& ios, uint16_t port)
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
    const std::lock_guard<std::mutex> lock{mutex_};
    sessions_.erase(uuid);
}

void ChatServer::HandleNewSession(ChatSessionPtr session) {
    CHATROOM_LOG_INFO("New connection from {}", session->client_ep());
    session->set_close_callback([](auto session) {
        ChatService::instance().HandleSessionClosed(session);
    });
    session->set_read_callback([](auto session, auto& packet) {
        if (session->is_closed()) return;
        ChatService::instance().HandleRecvPacket(session, packet);
    });
    session->Start();
}
}
