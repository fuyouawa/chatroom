#pragma once
#include "chatsession.h"
#include <mutex>
#include <unordered_map>

namespace chatroom
{
class ChatServer
{
public:
    ChatServer(IOService& ios, uint16_t port);

    void Start();

	void RemoveSession(const std::string& uuid);

private:
    void HandleNewSession(ChatSessionPtr session);

    Acceptor acceptor_;
    std::mutex mutex_;
    std::unordered_map<std::string, ChatSessionPtr> sessions_;
};
}