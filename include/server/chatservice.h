#pragma once
#include <unordered_map>
#include "base/basic.h"
#include "chatsession.h"
#include "message/login.pb.h"
#include "message/register.pb.h"

namespace chatroom
{
class ChatService : public Singleton<ChatService>
{
public:
    void HandleRecvPacket(ChatSessionPtr session, const RecvPacket& packet);
    void HandleSessionClosed(ChatSessionPtr session);

private:
    void Register(ChatSessionPtr session, const message::Register& msg);
    void Login(ChatSessionPtr session, const message::Login& msg);

    std::unordered_map<uint, ChatSessionPtr> logined_user_map_;
};
}