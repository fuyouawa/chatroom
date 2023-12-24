#include "chatservice.h"
#include "public.h"
#include "tools/utils.h"

namespace chatroom
{
void ChatService::HandleRecvPacket(ChatSessionPtr session, const RecvPacket& packet) {
    switch (packet.msg_type())
    {
    case kLoginMsg:
        Login(session, Deserialize<model::User>(packet.data_buf()));
        break;
    default:
        break;
    }
}

void ChatService::Login(ChatSessionPtr session, const model::User& data) {
    
}
}