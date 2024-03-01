#include "chatservice.h"
#include "tools/logger.h"
#include "model/user_model.h"
#include "model/friends_model.h"

#include "common/tools/converter.h"
#include "common/core/msg_id.h"

#include "common/msgpb/login.pb.h"
#include "common/msgpb/register.pb.h"
#include "common/msgpb/add_friend.pb.h"
#include "common/msgpb/remove_friend.pb.h"
#include "common/msgpb/get_friends.pb.h"
#include "common/msgpb/add_group.pb.h"
#include "common/msgpb/remove_group.pb.h"

#include "common/msgpb/register_ack.pb.h"
#include "common/msgpb/login_ack.pb.h"
#include "common/msgpb/add_friend_ack.pb.h"
#include "common/msgpb/remove_friend_ack.pb.h"
#include "common/msgpb/get_friends_ack.pb.h"
#include "common/msgpb/add_group_ack.pb.h"
#include "common/msgpb/remove_group_ack.pb.h"

#include <ranges>

namespace chatroom {
namespace {
void HandleRegister(ChatSessionPtr session, const msgpb::Register& msg) {
    CHATROOM_LOG_INFO("Register({}): Name:{}, Password:{}", session->client_ep(), msg.name(), msg.password());
    User register_user{};
    register_user.set_name(msg.name());
    register_user.set_password(msg.password());
    register_user.set_register_time(std::chrono::system_clock::now());

    msgpb::RegisterAck register_ack;
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
    session->Send(msgid::kMsgRegisterAck, register_ack);
}

void HandleLogin(ChatSessionPtr session, const msgpb::Login& msg) {
    CHATROOM_LOG_INFO("Login({}): Account:{}, Password:{}", session->client_ep(), msg.account(), msg.password());
    msgpb::LoginAck login_ack;
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
        login_ack.set_user_name(user.name());
        CHATROOM_LOG_INFO("Login success({}): Name:{}, Account:{}", session->client_ep(), user.name(), user.account());
    }
    catch(const std::exception& e)
    {
        login_ack.set_success(false);
        login_ack.set_errmsg("账号不存在!");
        CHATROOM_LOG_INFO("Login faild({}): {}", session->client_ep(), e.what());
    }
    
send:
    session->Send(msgid::kMsgLoginAck, login_ack);
}

void HandleAddFriend(ChatSessionPtr session, const msgpb::AddFriend& msg) {
    CHATROOM_LOG_INFO("User({}) try to add friend({})", msg.user_id(), msg.friend_id());
    msgpb::AddFriendAck ack;
    if (msg.user_id() == msg.friend_id()) {
        ack.set_success(false);
        ack.set_errmsg("不可添加自己为好友!");
        CHATROOM_LOG_INFO("User({}) add friend({}) faild: Try to add self!", msg.user_id(), msg.friend_id());
        goto send;
    }
    try
    {
        auto friends = model::QueryFriends(msg.user_id());
        if (std::ranges::find(friends, msg.user_id()) != friends.end()) {
            ack.set_success(false);
            ack.set_errmsg("你们已经是好友了!");
            CHATROOM_LOG_INFO("User({}) add friend({}) faild: They are already friends!", msg.user_id(), msg.friend_id());
            goto send;
        }
        model::InsertFriend(msg.user_id(), msg.friend_id());
        ack.set_success(true);
        CHATROOM_LOG_INFO("User({}) add friend({}) success!", msg.user_id(), msg.friend_id());
    }
    catch(const std::exception& e)
    {
        ack.set_errmsg(e.what());
        CHATROOM_LOG_INFO("User({}) add friend({}) faild:", msg.user_id(), msg.friend_id(), e.what());
    }
send:
    session->Send(msgid::kMsgAddFriendAck, ack);
}

void HandleRemoveFriend(ChatSessionPtr session, const msgpb::RemoveFriend& msg) {
    CHATROOM_LOG_INFO("User({}) try to remove friend({})", msg.user_id(), msg.friend_id());
    msgpb::RemoveFriendAck ack;
    try
    {
        model::RemoveFriend(msg.user_id(), msg.friend_id());
        ack.set_success(true);
        CHATROOM_LOG_INFO("User({}) remove friend({}) success!", msg.user_id(), msg.friend_id());
    }
    catch(const std::exception& e)
    {
        ack.set_success(false);
        ack.set_errmsg(e.what());
        CHATROOM_LOG_INFO("User({}) remove friend({}) faild:", msg.user_id(), msg.friend_id(), e.what());
    }
    session->Send(msgid::kMsgRemoveFriendAck, ack);
}

void HandleGetFriends(ChatSessionPtr session, const msgpb::GetFriends& msg) {
    CHATROOM_LOG_INFO("User({}) try to get friends", msg.user_id());
    msgpb::GetFriendsAck ack;
    try
    {
        auto friends_id = model::QueryFriends(msg.user_id());
        for (auto& id: friends_id) {
            auto friend_info = model::QueryUser(id);
            auto new_elem = ack.add_friends_info();
            new_elem->set_id(id);
            new_elem->set_name(friend_info.name());
        }
        ack.set_success(true);
        CHATROOM_LOG_INFO("User({}) get friends success!", msg.user_id());
    }
    catch(const std::exception& e)
    {
        ack.set_success(false);
        ack.set_errmsg(e.what());
        CHATROOM_LOG_INFO("User({}) get friends failed:{}", msg.user_id(), e.what());
    }
    session->Send(msgid::kMsgGetFriendsAck, ack);
}
}   // namespace

void ChatService::HandleRecvPacket(ChatSessionPtr session, const RecvPacket& packet) {
    switch (packet.msgid())
    {
    case msgid::kMsgRegister:
        HandleRegister(session, packet.DeserializeData<msgpb::Register>());
        break;
    case msgid::kMsgLogin:
        HandleLogin(session, packet.DeserializeData<msgpb::Login>());
        break;
    case msgid::kMsgAddFriend:
        HandleAddFriend(session, packet.DeserializeData<msgpb::AddFriend>());
        break;
    case msgid::kMsgRemoveFriend:
        HandleRemoveFriend(session, packet.DeserializeData<msgpb::RemoveFriend>());
        break;
    case msgid::kMsgGetFriends:
        HandleGetFriends(session, packet.DeserializeData<msgpb::GetFriends>());
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