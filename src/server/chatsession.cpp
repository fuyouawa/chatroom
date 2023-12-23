#include "chatsession.h"
#include <coroutine>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace chatroom
{
ChatSession::ChatSession(Socket&& socket, ChatServer* server)
    : socket_{std::move(socket)},
    server_{server},
    uuid_{boost::uuids::to_string(boost::uuids::random_generator()())}
{
}


void ChatSession::Start()
{

}
}
