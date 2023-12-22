#pragma once
#include "chatsession.h"
#include <mutex>
#include <unordered_map>

namespace chatroom
{
class ChatServer
{
public:
    ChatServer(io_service& ios, short port);

	void RemoveSession(std::string);

private:
	void HandleAccept(std::shared_ptr<ChatSession> session, const boost::system::error_code& ec);
	void StartAccept();

    ip::tcp::acceptor acceptor_;
    std::mutex mutex_;
    std::unordered_map<std::string, std::shared_ptr<ChatSession>> sessions_;
};
}