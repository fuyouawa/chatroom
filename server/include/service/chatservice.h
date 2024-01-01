#pragma once
#include <unordered_map>
#include "service/chatsession.h"
#include "message/user_login.pb.h"
#include "message/user_register.pb.h"
#include "model/user.h"
#include "basic/singleton.h"


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

    void HandleRegister(ChatSessionPtr session, const message::UserRegister& msg);
    void HandleLogin(ChatSessionPtr session, const message::UserLogin& msg);

    std::unordered_map<uint, std::tuple<ChatSessionPtr, User>> logged_session_map_;
};
}