#pragma once
#include "base/basic.h"
#include "chatsession.h"
#include "model/User.pb.h"

namespace chatroom
{
class ChatService : public Singleton<ChatService>
{
public:
    void HandleRecvPacket(ChatSessionPtr session, const RecvPacket& packet);

private:
    void Login(ChatSessionPtr session, const model::User& user);
};
}