#pragma once
#include <utility>
#include <boost/asio.hpp>
#include <string>
#include "base/basic.h"
#include "base/usings.h"
#include "tools/packet.h"

namespace chatroom
{
class ChatServer;
class ChatSession : public std::enable_shared_from_this<ChatSession>
{
public:
    ChatSession(Socket&& socket, ChatServer* server);

    void Start();
    void Close();

    Socket& socket() { return socket_; }
    std::string uuid() { return uuid_; }

private:
    bool is_closed_;
    Socket socket_;
    ChatServer* server_;
    std::string uuid_;
    std::shared_ptr<RecvPacket> recv_packet_;
};

using ChatSessionPtr = std::shared_ptr<ChatSession>;
}