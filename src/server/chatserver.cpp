#include <coroutine>
#include "ioservice_pool.h"
#include "chatserver.h"
#include "tools/logger.h"

namespace chatroom
{
ChatServer::ChatServer(io_service& ios, uint16_t port)
    : acceptor_{ios, ip::tcp::endpoint{ip::tcp::v4(), port}}
{
}

void ChatServer::Start() {
    co_spawn(acceptor_.get_executor(), [this]()->awaitable<void>{ co_await StartAccept(); }, detached);
}

awaitable<void> ChatServer::StartAccept() {
    try
    {
        while (true) {
            auto& ios = IOServicePool::instance().NextIOService();
            auto socket = co_await acceptor_.async_accept(ios, use_awaitable);
            CHATROOM_LOG_INFO("New connection from {}", socket.remote_endpoint());

            auto session = std::make_shared<ChatSession>(std::move(socket), this);
            session->Start();
            std::lock_guard<std::mutex> lock{mutex_};
            sessions_.insert({session->uuid(), session});
        }
    }
    catch(const std::exception& e)
    {
        CHATROOM_LOG_ERROR("Session accept failed! errmsg:{}", e.what());
    }
}
}
