#pragma once
#include <boost/asio.hpp>
#include <string>

namespace chatroom
{
using namespace boost::asio;

class ChatServer;
class ChatSession : public std::enable_shared_from_this<ChatSession>
{
public:
    ChatSession(io_service& ios, ChatServer* server);

    void Start();

    ip::tcp::socket& socket();
    std::string uuid();

private:
    ip::tcp::socket socket_;
    ChatServer* server_;
};
}