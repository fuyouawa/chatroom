#include "chatservice.h"
#include "public.h"
#include "tools/logger.h"
#include "tools/converter.h"

#include "model/user_model.h"

#include "message/register_ack.pb.h"
#include "message/login_ack.pb.h"
#include "message/emergency.pb.h"

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

void ChatService::HandleSessionClosed(ChatSessionPtr session) {
    CHATROOM_LOG_INFO("session({}) closed connection!", session->socket().remote_endpoint());
    if (session->account() != 0) {
        logined_user_map_.erase(session->account());
        session->set_account(0);
    }
}

void ChatService::Register(ChatSessionPtr session, const message::Register& msg) {
    CHATROOM_LOG_INFO("Session({}) wanna register! Name:{}, Password:{}", session->socket().remote_endpoint(), msg.name(), msg.password());
    User register_user{};
    register_user.set_name(msg.name());
    register_user.set_password(msg.password());
    register_user.set_register_time(std::chrono::system_clock::now());
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
    CHATROOM_LOG_INFO("Session({}) wanna login! Account:{} Password:{}", session->socket().remote_endpoint(), msg.account(), msg.password());
    auto exp = UserModel::Query(msg.account());
    message::LoginAck login_ack;
    if (exp.has_value()) {
        auto& user = exp.value();
        if (user.password() != msg.password()) {
            login_ack.set_success(false);
            login_ack.set_errmsg("密码错误!");
            goto send;
        }
        if (user.state() == kOnline) {
            logined_user_map_[user.account()]->SendEmergency(kForceOfflineEvent, "一个新设备正在登录您的账户, 您将被强制下线");
        }
        else {
            user.set_state(kOnline);
            UserModel::Update(user);
        }
        session->set_account(user.account());
        logined_user_map_[user.account()] = session;
        login_ack.set_success(true);
    }
send:
    session->Send(kLoginMsgAck, login_ack);
}
}