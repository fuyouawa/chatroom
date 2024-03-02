#include "service/chatservice.h"
#include "tools/logger.h"
#include "model/friends.h"
#include "model/group.h"

#include "common/core/msg_id.h"

#include "common/msgpb/login.pb.h"
#include "common/msgpb/register.pb.h"
#include "common/msgpb/add_friend.pb.h"
#include "common/msgpb/remove_friend.pb.h"
#include "common/msgpb/get_friends.pb.h"
#include "common/msgpb/create_group.pb.h"
#include "common/msgpb/remove_group.pb.h"
#include "common/msgpb/get_joined_groups.pb.h"
#include "common/msgpb/join_group.pb.h"
#include "common/msgpb/quit_group.pb.h"

#include "common/msgpb/register_ack.pb.h"
#include "common/msgpb/login_ack.pb.h"
#include "common/msgpb/add_friend_ack.pb.h"
#include "common/msgpb/remove_friend_ack.pb.h"
#include "common/msgpb/get_friends_ack.pb.h"
#include "common/msgpb/create_group_ack.pb.h"
#include "common/msgpb/remove_group_ack.pb.h"
#include "common/msgpb/get_joined_groups_ack.pb.h"
#include "common/msgpb/join_group_ack.pb.h"
#include "common/msgpb/quit_group_ack.pb.h"

#include <ranges>

namespace chatroom {
namespace {
void HandleRegister(ChatSessionPtr session, const msgpb::Register& msg) {
    CHATROOM_LOG_INFO("Register({}): Name:{}, Password:{}", session->client_ep(), msg.name(), msg.password());
    model::UserInfo register_user {
        .name = msg.name(),
        .password = msg.password(),
        .online = false
    };
    msgpb::RegisterAck register_ack;
    try
    {
        const auto user_id = model::InsertUser(register_user);
        register_ack.set_success(true);
        register_ack.set_user_id(user_id);
        CHATROOM_LOG_INFO("Register success({}): Name:{}, Account:{}", session->client_ep(), msg.name(), user_id);
    }
    catch(const std::exception& e)
    {
        register_ack.set_success(false);
        register_ack.set_errmsg(e.what());
        CHATROOM_LOG_ERROR("Register faild({}): {}", session->client_ep(), e.what());
    }
    session->Send(msgid::kMsgRegisterAck, register_ack);
}

void HandleLogin(ChatSessionPtr session, const msgpb::Login& msg) {
    CHATROOM_LOG_INFO("Login({}): Account:{}, Password:{}", session->client_ep(), msg.user_id(), msg.password());
    msgpb::LoginAck login_ack;
    try
    {
        auto user_info = model::QueryUser(msg.user_id());
        if (user_info.password != msg.password()) {
            login_ack.set_success(false);
            login_ack.set_errmsg("密码错误!");
            CHATROOM_LOG_INFO("Register faild({}): password occur!", session->client_ep());
            goto send;
        }
        if (user_info.online) {
            const auto logged_user = ChatService::instance().GetLoggedUserInfo(user_info.id);
            login_ack.set_success(false);
            login_ack.set_errmsg("一个设备正在登录这个账户!");
            CHATROOM_LOG_WARNING("One device({}({})) is already logged into the account, and the other device({}({})) is trying to log in.",
            logged_user.name, logged_user.id, user_info.name, user_info.id);
            goto send;
        }
        user_info.online = true;
        ChatService::instance().Login(session, user_info);
        login_ack.set_success(true);
        login_ack.set_user_name(user_info.name);
        CHATROOM_LOG_INFO("Login success({}): Name:{}, Account:{}", session->client_ep(), user_info.name, user_info.id);
    }
    catch(const std::exception& e)
    {
        login_ack.set_success(false);
        login_ack.set_errmsg(e.what());
        CHATROOM_LOG_ERROR("Login faild({}): {}", session->client_ep(), e.what());
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
            CHATROOM_LOG_WARNING("User({}) add friend({}) faild: They are already friends!", msg.user_id(), msg.friend_id());
            goto send;
        }
        model::InsertFriend(msg.user_id(), msg.friend_id());
        ack.set_success(true);
        CHATROOM_LOG_INFO("User({}) add friend({}) success!", msg.user_id(), msg.friend_id());
    }
    catch(const std::exception& e)
    {
        ack.set_success(false);
        ack.set_errmsg(e.what());
        CHATROOM_LOG_ERROR("User({}) add friend({}) faild:", msg.user_id(), msg.friend_id(), e.what());
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
        CHATROOM_LOG_ERROR("User({}) remove friend({}) faild:", msg.user_id(), msg.friend_id(), e.what());
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
            auto elem = ack.add_friends_info();
            elem->set_id(id);
            elem->set_name(friend_info.name);
        }
        ack.set_success(true);
        CHATROOM_LOG_INFO("User({}) get friends success!", msg.user_id());
    }
    catch(const std::exception& e)
    {
        ack.set_success(false);
        ack.set_errmsg(e.what());
        CHATROOM_LOG_ERROR("User({}) get friends failed:{}", msg.user_id(), e.what());
    }
    session->Send(msgid::kMsgGetFriendsAck, ack);
}

void HandleCreateGroup(ChatSessionPtr session, const msgpb::CreateGroup& msg) {
    CHATROOM_LOG_INFO("User({}) try to add group({})", msg.user_id(), msg.group_name());
    msgpb::CreateGroupAck ack;
    try
    {
        auto group_id = model::InsertGroup(msg.user_id(), msg.group_name());
        ack.set_success(true);
        ack.set_group_id(group_id);
        CHATROOM_LOG_INFO("User({}) add group({}) success! return id:{}", msg.user_id(), msg.group_name(), group_id);
    }
    catch(const std::exception& e)
    {
        ack.set_success(false);
        ack.set_errmsg(e.what());
        CHATROOM_LOG_ERROR("User({}) add group({}) faild:{}", msg.user_id(), msg.group_name(), e.what());
    }
    session->Send(msgid::kMsgCreateGroupAck, ack);
}

void HandleRemoveGroup(ChatSessionPtr session, const msgpb::RemoveGroup& msg) {
    CHATROOM_LOG_INFO("User({}) try to remove group({})", msg.user_id(), msg.group_id());
    msgpb::RemoveGroupAck ack;
    try
    {
        model::RemoveGroup(msg.user_id(), msg.group_id());
        ack.set_success(true);
        CHATROOM_LOG_INFO("User({}) remove group({}) success!", msg.user_id(), msg.group_id());
    }
    catch(const std::exception& e)
    {
        ack.set_success(false);
        ack.set_errmsg(e.what());
        CHATROOM_LOG_ERROR("User({}) remove group({}) faild:", msg.user_id(), msg.group_id(), e.what());
    }
    session->Send(msgid::kMsgRemoveFriendAck, ack);
}

void HandleGetJoinedGroups(ChatSessionPtr session, const msgpb::GetJoinedGroups& msg) {
    CHATROOM_LOG_INFO("User({}) try to get joined groups", msg.user_id());
    msgpb::GetJoinedGroupsAck ack;
    try
    {
        auto groups_id = model::GetJoinedGroups(msg.user_id());
        for (auto& id: groups_id) {
            auto info = model::QueryGroup(id);
            auto elem = ack.add_groups_info();
            elem->set_id(info.id);
            elem->set_name(info.name);
        }
        ack.set_success(true);
        CHATROOM_LOG_INFO("User({}) get joined groups success!", msg.user_id());
    }
    catch(const std::exception& e)
    {
        ack.set_success(false);
        ack.set_errmsg(e.what());
        CHATROOM_LOG_ERROR("User({}) get joined groups failed:{}", msg.user_id(), e.what());
    }
    session->Send(msgid::kMsgGetJoinedGroupsAck, ack);
}

void HandleJoinGroup(ChatSessionPtr session, const msgpb::JoinGroup& msg) {
    CHATROOM_LOG_INFO("User({}) try to add group(id:{})", msg.user_id(), msg.group_id());
    msgpb::JoinGroupAck ack;
    try
    {
        model::JoinGroup(msg.user_id(), msg.group_id());
        auto info = model::QueryGroup(msg.group_id());
        ack.set_success(true);
        ack.set_group_name(info.name);
        CHATROOM_LOG_INFO("User({}) add group(id:{}) success!", msg.user_id(), msg.group_id());
    }
    catch(const std::exception& e)
    {
        ack.set_success(false);
        ack.set_errmsg(e.what());
        CHATROOM_LOG_ERROR("User({}) add group(id:{}) faild:{}", msg.user_id(), msg.group_id(), e.what());
    }
    session->Send(msgid::kMsgJoinGroupAck, ack);
}


void HandleQuitGroup(ChatSessionPtr session, const msgpb::QuitGroup& msg) {
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
    case msgid::kMsgCreateGroup:
        HandleCreateGroup(session, packet.DeserializeData<msgpb::CreateGroup>());
        break;
    case msgid::kMsgRemoveGroup:
        HandleRemoveGroup(session, packet.DeserializeData<msgpb::RemoveGroup>());
        break;
    case msgid::kMsgGetJoinedGroups:
        HandleGetJoinedGroups(session, packet.DeserializeData<msgpb::GetJoinedGroups>());
        break;
    case msgid::kMsgJoinGroup:
        HandleJoinGroup(session, packet.DeserializeData<msgpb::JoinGroup>());
        break;
    case msgid::kMsgQuitGroup:
        HandleQuitGroup(session, packet.DeserializeData<msgpb::QuitGroup>());
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
        model::UpdateUserOnline(session->user_id(), false);
        logged_session_map_.erase(session->user_id());
        session->set_user_id(0);
        session->set_logging(false);
    }
}

void ChatService::Login(ChatSessionPtr session, const model::UserInfo& user) {
    session->set_user_id(user.id);
    session->set_logging(true);
    logged_session_map_[user.id] = {session, user};
    model::UpdateUserOnline(session->user_id(), true);
}
}   // namespace chatroom