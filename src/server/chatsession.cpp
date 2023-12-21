#include <coroutine>
#include "chatsession.h"

namespace cluster_chat_room
{
ChatSession::ChatSession(ip::tcp::socket&& socket)
    : socket_{std::move(socket)}
{
}
}
