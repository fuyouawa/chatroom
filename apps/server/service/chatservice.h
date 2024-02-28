#pragma once
#include <unordered_map>
#include "service/chatsession.h"
#include "model/user.h"

#include "common/core/singleton.h"
#include "common/msgpb/user_login.pb.h"
#include "common/msgpb/user_register.pb.h"


namespace chatroom
{

class ChatService : public Singleton<ChatService>
{
public:
    void HandleRecvPacket(ChatSessionPtr session, const RecvPacket& packet);
    void HandleSessionClosed(ChatSessionPtr session);

private:
    void Logout(ChatSessionPtr session);
    void Login(ChatSessionPtr session, const User& user);

    void HandleRegister(ChatSessionPtr session, const msgpb::UserRegister& msg);
    void HandleLogin(ChatSessionPtr session, const msgpb::UserLogin& msg);

    std::unordered_map<uint, std::tuple<ChatSessionPtr, User>> logged_session_map_;
};
}