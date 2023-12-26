#include "chatservice.h"
#include "public.h"
#include "tools/logger.h"

namespace chatroom
{
void ChatService::HandleRecvPacket(ChatSessionPtr session, const RecvPacket& packet) {
    switch (packet.msg_type())
    {
    case kLoginMsg:
        Login(session, packet.DeserializeData<message::Login>());
        break;
    default:
        break;
    }
}

void ChatService::Login(ChatSessionPtr session, const message::Login& msg) {
    CHATROOM_LOG_INFO("name:{} password:{}", msg.name(), msg.password());
}
}