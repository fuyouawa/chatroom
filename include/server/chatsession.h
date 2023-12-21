#pragma once
#include <boost/asio.hpp>

namespace cluster_chat_room
{
using namespace boost::asio;

class ChatSession : public std::enable_shared_from_this<ChatSession>
{
public:
    ChatSession(ip::tcp::socket&& socket);

private:
    ip::tcp::socket socket_;
};
}