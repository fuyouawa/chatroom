#pragma once
#include <utility>
#include <boost/asio.hpp>
#include <string>
#include "base/basic.h"
#include "base/usings.h"

namespace chatroom
{
class ChatServer;
class ChatSession : public std::enable_shared_from_this<ChatSession>
{
public:
    ChatSession(Socket&& socket, ChatServer* server);

    void Start();

    Socket& socket() { return socket_; }
    std::string uuid() { return uuid_; }

private:
    Socket socket_;
    ChatServer* server_;
    std::string uuid_;
};

using ChatSessionPtr = std::shared_ptr<ChatSession>;
}