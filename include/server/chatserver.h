#pragma once
#include "chatsession.h"
#include <mutex>
#include <unordered_map>

namespace chatroom
{
class ChatServer
{
public:
    ChatServer(io_service& ios, uint16_t port);

    void Start();

	void RemoveSession(std::string);

private:
	awaitable<void> StartAccept();

    ip::tcp::acceptor acceptor_;
    std::mutex mutex_;
    std::unordered_map<std::string, std::shared_ptr<ChatSession>> sessions_;
};
}