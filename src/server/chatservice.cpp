#include "chatservice.h"
#include "public.h"
#include "tools/logger.h"

namespace chatroom
{
void ChatService::HandleRecvPacket(ChatSessionPtr session, const RecvPacket& packet) {
    switch (packet.msg_type())
    {
    case kLoginMsg:
        Login(session, packet.DeserializeData<model::User>());
        break;
    default:
        break;
    }
}

void ChatService::Login(ChatSessionPtr session, const model::User& user) {
    CHATROOM_LOG_INFO("name:{} password:{}", user.name(), user.password());
}
}