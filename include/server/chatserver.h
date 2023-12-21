#pragma once
#include "chatsession.h"

namespace cluster_chat_room
{
class ChatServer
{
public:
    ChatServer(io_service& ios, short port);

    void Start();

private:
    awaitable<void> StartAccept();

    ip::tcp::acceptor acceptor_;
};
}