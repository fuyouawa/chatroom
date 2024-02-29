#include "chatservice.h"
#include "tools/logger.h"
#include "model/user_model.h"
#include "model/friends_model.h"

#include "common/tools/converter.h"
#include "common/core/msg_id.h"

#include "common/msgpb/user_login.pb.h"
#include "common/msgpb/user_register.pb.h"
#include "common/msgpb/user_add_friend.pb.h"
#include "common/msgpb/user_remove_friend.pb.h"

#include "common/msgpb/user_register_ack.pb.h"
#include "common/msgpb/user_login_ack.pb.h"
#include "common/msgpb/user_add_friend_ack.pb.h"
#include "common/msgpb/user_remove_friend_ack.pb.h"

namespace chatroom {
namespace {
void HandleRegister(ChatSessionPtr session, const msgpb::UserRegister& msg) {
    CHATROOM_LOG_INFO("Register({}): Name:{}, Password:{}", session->client_ep(), msg.name(), msg.password());
    User register_user{};
    register_user.set_name(msg.name());
    register_user.set_password(msg.password());
    register_user.set_register_time(std::chrono::system_clock::now());

    msgpb::UserRegisterAck register_ack;
    try
    {
        const auto account = model::InsertUser(register_user);
        register_ack.set_success(true);
        register_ack.set_account(account);
        CHATROOM_LOG_INFO("Register success({}): Name:{}, Account:{}", session->client_ep(), msg.name(), account);
    }
    catch(const std::exception& e)
    {
        register_ack.set_success(false);
        register_ack.set_errmsg(e.what());
        CHATROOM_LOG_INFO("Register faild({}): {}", session->client_ep(), e.what());
    }
    session->Send(MessageID::kUserRegisterAck, register_ack);
}

void HandleLogin(ChatSessionPtr session, const msgpb::UserLogin& msg) {
    CHATROOM_LOG_INFO("Login({}): Account:{}, Password:{}", session->client_ep(), msg.account(), msg.password());
    msgpb::UserLoginAck login_ack;
    try
    {
        auto user = model::QueryUser(msg.account());
        if (user.password() != msg.password()) {
            login_ack.set_success(false);
            login_ack.set_errmsg("密码错误!");
            CHATROOM_LOG_INFO("Register faild({}): password occur!", session->client_ep());
            goto send;
        }
        if (user.state() == UserState::kOnline) {
            const auto logged_user = ChatService::instance().GetLoggedUserInfo(user.account());
            CHATROOM_LOG_WARNING("One device({}({})) is already logged into the account, and the other device({}({})) is trying to log in.",
            logged_user.name(), logged_user.account(), user.name(), user.account());
            login_ack.set_success(false);
            login_ack.set_errmsg("一个设备正在登录这个账户!");
            goto send;
        }
        user.set_state(UserState::kOnline);
        ChatService::instance().Login(session, user);
        login_ack.set_success(true);
        CHATROOM_LOG_INFO("Login success({}): Name:{}, Account:{}", session->client_ep(), user.name(), user.account());
    }
    catch(const std::exception& e)
    {
        login_ack.set_success(false);
        login_ack.set_errmsg("账号不存在!");
        CHATROOM_LOG_INFO("Login faild({}): {}", session->client_ep(), e.what());
    }
    
send:
    session->Send(MessageID::kUserLoginAck, login_ack);
}

void HandleAddFriend(ChatSessionPtr session, const msgpb::UserAddFriend& msg) {
    msgpb::UserAddFriendAck ack;
    try
    {
        CHATROOM_LOG_INFO("Add friend({}): User Account:{}, Friend Account:{}", session->client_ep(), msg.user_id(), msg.friend_id());
        model::InsertFriend(msg.user_id(), msg.friend_id());
        ack.set_success(true);
        CHATROOM_LOG_INFO("Add friend success({}): User Account:{}, Friend Account:{}", session->client_ep(), msg.user_id(), msg.friend_id());
    }
    catch(const std::exception& e)
    {
        ack.set_success(false);
        ack.set_errmsg(e.what());
        CHATROOM_LOG_INFO("Add friend faild({}): {}", session->client_ep(), e.what());
    }
    session->Send(MessageID::kUserAddFriendAck, ack);
}

void HandleRemoveFriend(ChatSessionPtr session, const msgpb::UserRemoveFriend& msg) {

}
}   // namespace

void ChatService::HandleRecvPacket(ChatSessionPtr session, const RecvPacket& packet) {
    switch (packet.msgid())
    {
    case MessageID::kUserRegister:
        HandleRegister(session, packet.DeserializeData<msgpb::UserRegister>());
        break;
    case MessageID::kUserLogin:
        HandleLogin(session, packet.DeserializeData<msgpb::UserLogin>());
        break;
    case MessageID::kUserAddFriend:
        HandleAddFriend(session, packet.DeserializeData<msgpb::UserAddFriend>());
        break;
    case MessageID::kUserRemoveFriend:
        HandleRemoveFriend(session, packet.DeserializeData<msgpb::UserRemoveFriend>());
        break;
    default:
        break;
    }
}

void ChatService::HandleSessionClosed(ChatSessionPtr session) {
    CHATROOM_LOG_INFO("{} closed one connection!", session->client_ep());
    Logout(session);
}

void ChatService::Logout(ChatSessionPtr session) {
    if (session->logging()) {
        model::UpdateUserState(session->account(), UserState::kOffline);
        logged_session_map_.erase(session->account());
        session->set_account(0);
        session->set_logging(false);
    }
}

void ChatService::Login(ChatSessionPtr session, const User& user) {
    session->set_account(user.account());
    session->set_logging(true);
    logged_session_map_[user.account()] = {session, user};
    model::UpdateUserState(session->account(), UserState::kOnline);
}
}   // namespace chatroom