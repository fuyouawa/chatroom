#pragma once
#include <unordered_map>
#include "service/chatsession.h"
#include "model/user.h"

#include "common/core/singleton.h"


namespace chatroom {
class ChatService : public Singleton<ChatService> {
public:
    void HandleRecvPacket(ChatSessionPtr session, const RecvPacket& packet);
    void HandleSessionClosed(ChatSessionPtr session);

    void Logout(ChatSessionPtr session);
    void Login(ChatSessionPtr session, const model::UserInfo& user);

    auto& GetLoggedSession(int user_id) const { return logged_session_map_.at(user_id).first; }
    auto& GetLoggedUserInfo(int user_id) const { return logged_session_map_.at(user_id).second; }

private:
    std::unordered_map<int, std::pair<ChatSessionPtr, model::UserInfo>> logged_session_map_;
};
}   // namespace chatroom