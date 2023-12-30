#include "chatservice.h"
#include "public.h"
#include "tools/logger.h"
#include "tools/converter.h"

#include "model/user_model.h"

#include "message/register_ack.pb.h"
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
    CHATROOM_LOG_INFO("Session({}) wanna register! Name:{}, Password:{}", session->socket().remote_endpoint(), msg.name(), msg.password());
    User register_user{};
    register_user.set_name(msg.name());
    register_user.set_password(msg.password());
    register_user.set_register_time(Converter::ToTimepoint(msg.register_time()));
    register_user.set_state(kOffline);
    auto exp = UserModel::Insert(register_user);

    message::RegisterAck register_ack;
    register_ack.set_success(exp.has_value());
    if (exp.has_value())
    {
        auto account = exp.value();
        CHATROOM_LOG_INFO("Session({}) register success! Account:{}", session->socket().remote_endpoint(), account);
        register_ack.set_account(account);
    }
    else
    {
        auto errmsg = exp.error().what();
        CHATROOM_LOG_INFO("Session({}) register failed: {}", session->socket().remote_endpoint(), errmsg);
        register_ack.set_errmsg(errmsg);
    }
    session->Send(kRegisterMsgAck, register_ack);
}

void ChatService::Login(ChatSessionPtr session, const message::Login& msg) {

}
}