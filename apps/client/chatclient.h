#pragma once
#include <string_view>
#include <utility>
#include <boost/asio.hpp>
#include <google/protobuf/message.h>
#include "common/core/packet.h"
#include "common/core/msg_id.h"

namespace chatroom {
class ChatClient {
public:
    ChatClient(boost::asio::io_service& ios, std::string_view remote_address, uint16_t port);

    void Start();

private:
    void RunLoop();

    boost::asio::awaitable<void> AskAccountAndPassword();

    boost::asio::awaitable<size_t> Send(MessageID msgid, const google::protobuf::Message& msg);
    boost::asio::awaitable<RecvPacket> Receive();

    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::endpoint remote_ep_;
    int account_;
    std::string password_;
};
}   // namespace chatroom
