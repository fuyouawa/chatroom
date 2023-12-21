#include <coroutine>
#include "chatserver.h"

namespace cluster_chat_room
{
ChatServer::ChatServer(io_service& ios, short port)
    : acceptor_{ios, ip::tcp::endpoint{ip::tcp::v4(), port}}
{
}

void ChatServer::Start()
{
}

awaitable<void> ChatServer::StartAccept()
{
    for(;;)
    {
        auto socket = co_await acceptor_.async_accept(use_awaitable);
        
    }
}
}
