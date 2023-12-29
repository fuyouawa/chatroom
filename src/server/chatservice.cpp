#include "chatservice.h"
#include "public.h"
#include "tools/logger.h"
#include "model/user_model.h"
#include "tools/converter.h"

namespace chatroom
{
void ChatService::HandleRecvPacket(ChatSessionPtr session, const RecvPacket& packet) {
    switch (packet.msg_type())
    {
    case kRegisterMsg:
        Register(session, packet.DeserializeData<message::Register>());
        break;
    case kLoginMsg:
        Login(session, packet.DeserializeData<message::Login>());
        break;
    default:
        break;
    }
}

void ChatService::Register(ChatSessionPtr session, const message::Register& msg) {
    CHATROOM_LOG_INFO("Session({}) register! Name:{}, Password:{}", session->socket().remote_endpoint(), msg.name(), msg.password());
    User register_user{};
    register_user.set_name(msg.name());
    register_user.set_password(msg.password());
    register_user.set_register_time(Converter::TimepointCast(msg.register_time()));
    register_user.set_state(kOffline);
    if (auto opt = UserModel::Insert(register_user); opt.has_value()) {
        auto account = opt.value();
        
    }
}

void ChatService::Login(ChatSessionPtr session, const message::Login& msg) {

}
}