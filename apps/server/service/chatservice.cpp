#include "chatservice.h"
#include "tools/logger.h"
#include "model/user_model.h"

#include "common/tools/converter.h"
#include "common/core/msg_id.h"
#include "common/msgpb/user_register_ack.pb.h"
#include "common/msgpb/user_login_ack.pb.h"

namespace chatroom
{
void ChatService::HandleRecvPacket(ChatSessionPtr session, const RecvPacket& packet) {
    switch (packet.msgid())
    {
    case MessageID::kUserRegister:
        HandleRegister(session, packet.DeserializeData<message::UserRegister>());
        break;
    case MessageID::kUserLogin:
        HandleLogin(session, packet.DeserializeData<message::UserLogin>());
        break;
    default:
        break;
    }
}

void ChatService::HandleSessionClosed(ChatSessionPtr session) {
    CHATROOM_LOG_INFO("{} closed connection!", session->name());
    Logout(session);
}

void ChatService::Logout(ChatSessionPtr session) {
    if (session->logging()) {
        UserModel::UpdateState(session->account(), UserState::kOffline);
        logged_session_map_.erase(session->account());
        session->set_account(0);
        session->set_logging(false);
    }
}

void ChatService::Login(ChatSessionPtr session, const User& user) {
    session->set_account(user.account());
    session->set_logging(true);
    logged_session_map_[user.account()] = {session, user};
    UserModel::UpdateState(session->account(), UserState::kOnline);
}

void ChatService::HandleRegister(ChatSessionPtr session, const message::UserRegister& msg) {
    CHATROOM_LOG_INFO("{} wanna register! Name:{}, Password:{}", session->name(), msg.name(), msg.password());
    User register_user{};
    register_user.set_name(msg.name());
    register_user.set_password(msg.password());
    register_user.set_register_time(std::chrono::system_clock::now());

    message::UserRegisterAck register_ack;
    try
    {
        const auto account = UserModel::Insert(register_user);
        register_ack.set_success(true);
        CHATROOM_LOG_INFO("{} register success! Account:{}", session->name(), account);
        register_ack.set_account(account);
    }
    catch(const std::exception& e)
    {
        CHATROOM_LOG_INFO("{} register failed: {}", session->name(), e.what());
        register_ack.set_success(false);
        register_ack.set_errmsg(e.what());
    }
    session->Send(MessageID::kUserRegisterAck, register_ack);
}

void ChatService::HandleLogin(ChatSessionPtr session, const message::UserLogin& msg) {
    CHATROOM_LOG_INFO("{} wanna login! Account:{} Password:{}", session->name(), msg.account(), msg.password());
    message::UserLoginAck login_ack;
    try
    {
        auto user = UserModel::Query(msg.account());
        if (user.password() != msg.password()) {
            login_ack.set_success(false);
            login_ack.set_errmsg("密码错误!");
            goto send;
        }
        if (user.state() == UserState::kOnline) {
            const auto [_, logged_user] = logged_session_map_[user.account()];
            CHATROOM_LOG_INFO("One device({}({})) is already logged into the account, and the other device({}({})) is trying to log in.",
            logged_user.name(), logged_user.account(), user.name(), user.account());
            login_ack.set_success(false);
            login_ack.set_errmsg("一个设备正在登录这个账户!");
            goto send;
        }
        user.set_state(UserState::kOnline);
        UserModel::UpdateState(user.account(), UserState::kOnline);
        Login(session, user);
        login_ack.set_success(true);
        CHATROOM_LOG_INFO("{} login success! Username:{}({})", session->name(), user.name(), user.account());
    }
    catch(const std::exception& e)
    {
        login_ack.set_success(false);
        login_ack.set_errmsg("账号不存在!");
    }
    
send:
    session->Send(MessageID::kUserLoginAck, login_ack);
}
}