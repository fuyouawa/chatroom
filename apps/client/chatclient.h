#pragma once
#include <string_view>
#include <boost/asio.hpp>

namespace chatroom {
class ChatClient {
public:
    ChatClient(boost::asio::io_service& ios, std::string_view remote_address, uint16_t port);

    void Start();

private:
    void RunLoop();

    void AskAccountAndPassword();

    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::endpoint remote_ep_;
    int account_;
    std::string password_;
};
}   // namespace chatroom
