#include <coroutine>
#include "ioservice_pool.h"
#include "chatserver.h"

namespace cluster_chat_room
{
ChatServer::ChatServer(io_service& ios, short port)
    : acceptor_{ios, ip::tcp::endpoint{ip::tcp::v4(), port}}
{
}

void ChatServer::StartAccept() {
    auto& ios = IOServicePool::instance().NextIOService();
    auto session = std::make_shared<ChatSession>(ios, this);
    acceptor_.async_accept(session->socket(), [=, this](auto ec) {
        HandleAccept(session, ec);
    });
}

void ChatServer::HandleAccept(std::shared_ptr<ChatSession> session, const boost::system::error_code& ec) {
	if (!ec) {
		session->Start();
		std::lock_guard<std::mutex> lock{mutex_};
        sessions_.insert({session->uuid(), session});
	}
	else {
        
	}

	StartAccept();
}
}
