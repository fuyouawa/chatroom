#pragma once
#include <utility>
#include <boost/asio.hpp>
#include <string>

namespace chatroom
{
using namespace boost::asio;

class ChatServer;
class ChatSession : public std::enable_shared_from_this<ChatSession>
{
public:
    ChatSession(ip::tcp::socket&& socket, ChatServer* server);

    void Start();

    ip::tcp::socket& socket() { return socket_; }
    std::string uuid() { return uuid_; }

private:
    ip::tcp::socket socket_;
    ChatServer* server_;
    std::string uuid_;
};
}