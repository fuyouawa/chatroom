#pragma once
#include <mutex>
#include <unordered_map>
#include "service/chatservice.h"

namespace chatroom {
class ChatServer {
public:
    using Acceptor = boost::asio::ip::tcp::acceptor;

    ChatServer(boost::asio::io_service& ios, uint16_t port);

    void Start();

	void RemoveSession(const std::string& uuid);

private:
    void HandleNewSession(ChatSessionPtr session);
    void Initialization();

    Acceptor acceptor_;
    std::mutex mutex_;
    std::unordered_map<std::string, ChatSessionPtr> sessions_;
};
}   // namespace chatroom