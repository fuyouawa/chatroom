#include "chatclient.h"
#include "common/core/msg_id.h"
#include "common/core/packet.h"

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

#include "tools/console.h"

#include <chrono>

using namespace std::chrono_literals;

namespace chatroom {

namespace {
void TipBack() {
    console::Print("(按下任意键回退上一级)\n");
    console::InputKey();
}
void TipRetry() {
    console::Print("(按下任意键重新操作)\n");
    console::InputKey();
}
void TipContinue() {
    console::Print("(按下任意键继续)\n");
    console::InputKey();
}
}   // namespace


ChatClient::ChatClient(boost::asio::io_service& ios, std::string_view remote_address, uint16_t port)
    : socket_{ios},
    remote_ep_{boost::asio::ip::address::from_string(remote_address.data()), port},
    user_id_{0}
{
}

void ChatClient::Done() {
    done_ = true;
}

void ChatClient::Start() {
    socket_.connect(remote_ep_);
    RunLoop();
}

void ChatClient::RunLoop() {
    boost::asio::co_spawn(socket_.get_executor(), [this]()->boost::asio::awaitable<void> {
        try
        {
            while (co_await AskUserIdAndPassword()) {
                assert(user_id_);
                co_await BasicPanel();
            }
        }
        catch(const std::exception& e)
        {
            console::PrintError("Error occur:{}\n", e.what());
            TipContinue();
        }
    }, boost::asio::detached);

    boost::asio::co_spawn(socket_.get_executor(), [this]{ return ReceiveLoop(); }, boost::asio::detached);
}

boost::asio::awaitable<bool> ChatClient::AskUserIdAndPassword() {
    auto opt = console::Options({"登录", "注册", "退出"});
    switch (opt)
    {
    case 0:     // 登录
    {
    login_panel:
        console::Print("账号:"); auto user_id = console::GetUInt32();
        console::Print("密码:"); auto password = console::GetString();
        msgpb::Login login;
        login.set_user_id(user_id);
        login.set_password(password);
        co_await Send(msgid::kMsgLogin, login);
        auto ack = co_await Receive<msgpb::LoginAck>(msgid::kMsgLoginAck);
        if (ack.success()) {
            console::Print("登录成功!\n");
            user_id_ = user_id;
            user_name_ = ack.user_name();
            console::SetConsoleTitle(std::format("Chatroom App({})", user_name_));
        }
        else {
            console::PrintError("登录失败!原因:{}\n", ack.errmsg());
            goto login_panel;
        }
        co_return true;
    }
    case 1:     // 注册
    {
    register_panel:
        console::Print("注册昵称:"); auto name = console::GetString();
    reg_pwd_panel:
        console::Print("注册密码:"); auto password = console::GetString();
        console::Print("确认密码:"); auto password2 = console::GetString();
        if (password != password2) {
            console::Print("两次密码不正确, 请重新输入!\n");
            goto reg_pwd_panel;
        }
        msgpb::Register reg;
        reg.set_name(name);
        reg.set_password(password);
        co_await Send(msgid::kMsgRegister, reg);
        auto ack = co_await Receive<msgpb::RegisterAck>(msgid::kMsgRegisterAck);
        if (ack.success()) {
            console::Print("注册成功! 你的账号是:{}\n", ack.user_id());
            TipBack();
            goto login_panel;
        }
        else {
            console::PrintError("注册失败! 原因:{}\n", ack.errmsg());
            TipRetry();
            goto register_panel;
        }
        co_return true;
    }
    default:
        co_return false;
    }
}

boost::asio::awaitable<void> ChatClient::BasicPanel() {
main_panel:
    auto idx = console::Options({"查看个人信息", "查看好友列表", "查看群组列表", "添加好友", "删除好友", "创建群组", "删除群组", "加入群组", "退出登录"});
    switch (idx)
    {
    case 0:     // 查看个人信息
    {

        goto main_panel;
    }
    case 1:     // 查看好友列表
    {
        msgpb::GetFriends msg;
        msg.set_user_id(user_id_);
        co_await Send(msgid::kMsgGetFriends, msg);
        auto ack = co_await Receive<msgpb::GetFriendsAck>(msgid::kMsgGetFriendsAck);
        if (ack.success()) {
            if (ack.friends_info_size()) {
                std::vector<std::string> opts;
                for (auto &info : ack.friends_info()) {
                    opts.push_back(std::format("{} (账号: {})", info.name(), info.id()));
                }
                bool is_esc = false;
                auto idx = console::Options(opts, "[好友列表(Enter选中, Esc回退上一级)]", 0, &is_esc);
                if (is_esc) {
                    goto main_panel;
                }
            }
            else {
                console::Print("暂无好友\n");
                TipBack();
            }
        }
        else {
            console::PrintError("查看失败! 原因:{}\n", ack.errmsg());
            TipBack();
        }
        goto main_panel;
    }
    case 2:     // 查看群组列表
    {
    show_groups_panel:
        msgpb::GetJoinedGroups msg;
        msg.set_user_id(user_id_);
        co_await Send(msgid::kMsgGetJoinedGroups, msg);
        auto ack = co_await Receive<msgpb::GetJoinedGroupsAck>(msgid::kMsgGetJoinedGroupsAck);
        if (ack.success()) {
            if (ack.groups_info_size()) {
                std::vector<std::string> opts;
                for (auto &info : ack.groups_info()) {
                    opts.push_back(std::format("{} (ID: {})", info.name(), info.id()));
                }
                bool is_esc = false;
                size_t idx = 0;
                idx = console::Options(opts, "[群组列表(Enter选中, Esc回退上一级)]", 0, &is_esc);
                if (is_esc) {
                    goto main_panel;
                }
                auto select_group = ack.groups_info()[idx];
                idx = console::Options(
                    {"进入聊天", "查看信息", "退出群聊"},
                    std::format("当前选中的群是:{}(Enter选中, Esc回退上一级)", select_group.name()),
                    0, &is_esc);
                if (is_esc) {
                    goto show_groups_panel;
                }
                switch (idx)
                {
                case 0:     // 进入聊天
                {
                    break;
                }
                case 1:     // 查看信息
                {
                    break;
                }
                default:    // 退出群聊
                {
                    msgpb::QuitGroup msg;
                    msg.set_user_id(user_id_);
                    msg.set_group_id(select_group.id());
                    co_await Send(msgid::kMsgQuitGroup, msg);
                    auto ack = co_await Receive<msgpb::QuitGroupAck>(msgid::kMsgQuitGroupAck);
                    if (ack.success()) {
                        console::Print("群组删除成功!\n");
                    }
                    else {
                        console::PrintError("群组删除失败! 原因: {}\n", ack.errmsg());
                    }
                    TipBack();
                    goto show_groups_panel;
                }
                }
            }
            else {
                console::Print("暂无加入的群组\n");
                TipBack();
            }
        }
        else {
            console::PrintError("查看失败! 原因:{}\n", ack.errmsg());
            TipBack();
        }
        goto main_panel;
    }
    case 3:     // 添加好友
    {
    add_friend_panel:
        console::Print("输入要添加的好友账号:"); auto user_id = console::GetUInt32();
        msgpb::AddFriend msg;
        msg.set_user_id(user_id_);
        msg.set_friend_id(user_id);
        co_await Send(msgid::kMsgAddFriend, msg);
        auto ack = co_await Receive<msgpb::AddFriendAck>(msgid::kMsgAddFriendAck);
        if (ack.success()) {
            console::Print("好友添加成功!\n");
            TipBack();
        }
        else {
            console::PrintError("好友添加失败! 原因: {}\n", ack.errmsg());
            TipRetry();
            goto add_friend_panel;
        }
        goto main_panel;
    }
    case 4:     // 删除好友
    {
    remove_friend_panel:
        console::Print("输入要删除的好友账号:"); auto user_id = console::GetUInt32();
        msgpb::RemoveFriend msg;
        msg.set_user_id(user_id_);
        msg.set_friend_id(user_id);
        co_await Send(msgid::kMsgRemoveFriend, msg);
        auto ack = co_await Receive<msgpb::RemoveFriendAck>(msgid::kMsgRemoveFriendAck);
        if (ack.success()) {
            console::Print("好友删除成功!\n");
            TipBack();
        }
        else {
            console::PrintError("好友删除失败! 原因: {}\n", ack.errmsg());
            TipRetry();
            goto remove_friend_panel;
        }
        goto main_panel;
    }
    case 5:     // 创建群组
    {
    create_group_panel:
        console::Print("输入要创建的群组名称:"); auto name = console::GetString();
        msgpb::CreateGroup msg;
        msg.set_user_id(user_id_);
        msg.set_group_name(name);
        co_await Send(msgid::kMsgCreateGroup, msg);
        auto ack = co_await Receive<msgpb::CreateGroupAck>(msgid::kMsgCreateGroupAck);
        if (ack.success()) {
            console::Print("群组创建成功! 群组ID:{}\n", ack.group_id());
            TipBack();
        }
        else {
            console::PrintError("群组创建失败! 原因: {}\n", ack.errmsg());
            TipRetry();
            goto create_group_panel;
        }
        goto main_panel;
    }
    case 6:     // 删除群组
    {
    remove_group_panel:
        console::Print("输入要删除的群组ID:"); auto group_id = console::GetUInt32();
        msgpb::RemoveGroup msg;
        msg.set_user_id(user_id_);
        msg.set_group_id(group_id);
        co_await Send(msgid::kMsgRemoveGroup, msg);
        auto ack = co_await Receive<msgpb::RemoveGroupAck>(msgid::kMsgRemoveGroupAck);
        if (ack.success()) {
            console::Print("群组删除成功!\n");
            TipBack();
        }
        else {
            console::PrintError("群组删除失败! 原因: {}\n", ack.errmsg());
            TipRetry();
            goto remove_group_panel;
        }
        goto main_panel;
    }
    case 7:     // 加入群组
    {
    join_group_panel:
        console::Print("输入要加入的群组ID:"); auto group_id = console::GetUInt32();
        msgpb::JoinGroup msg;
        msg.set_user_id(user_id_);
        msg.set_group_id(group_id);
        co_await Send(msgid::kMsgJoinGroup, msg);
        auto ack = co_await Receive<msgpb::JoinGroupAck>(msgid::kMsgJoinGroupAck);
        if (ack.success()) {
            console::Print("群组加入成功!\n");
            TipBack();
        }
        else {
            console::PrintError("群组加入失败! 原因: {}\n", ack.errmsg());
            TipRetry();
            goto join_group_panel;
        }
        goto main_panel;
    }
    default:    // 退出登录
        user_id_ = 0;
        Done();
        break;
    }
}

boost::asio::awaitable<size_t> ChatClient::Send(uint16_t msgid, const google::protobuf::Message &msg) {
    SendPacket packet{msgid, msg};
    auto n = co_await boost::asio::async_write(socket_, boost::asio::buffer(packet.Pack()), boost::asio::use_awaitable);
    co_return n;
}

boost::asio::awaitable<RecvPacket> ChatClient::InternalReceive(int msgid) {
    auto exec = socket_.get_executor();
    boost::asio::steady_timer delayer{exec, 100ms};
    while (true)
    {
        assert(!done_);
        bool found = false;
        auto iter = recv_packets_list_.begin();
        for (;iter != recv_packets_list_.end(); ++iter) {
            if (iter->msgid() == msgid) {
                found = true;
                break;
            }
        }
        if (found) {
            auto tmp = std::move(*iter);
            recv_packets_list_.erase(iter);
            co_return std::move(tmp);
        }
        co_await delayer.async_wait(boost::asio::use_awaitable);
    }
}


boost::asio::awaitable<void> ChatClient::ReceiveLoop() {
    while (!done_) {
        PacketHeader network_header;
        auto n = co_await boost::asio::async_read(
            socket_,
            boost::asio::buffer(&network_header, sizeof(network_header)),
            boost::asio::use_awaitable);
        if (n == 0)
            throw boost::system::system_error(boost::asio::error::eof);
        assert(n == sizeof(network_header));
        RecvPacket recv_packet{network_header};

        n = co_await boost::asio::async_read(
            socket_,
            boost::asio::buffer(recv_packet.data(), recv_packet.data_size()),
            boost::asio::use_awaitable);
        if (n == 0)
            throw boost::system::system_error(boost::asio::error::eof);
        assert(n == recv_packet.data_size());

        recv_packets_list_.push_back(std::move(recv_packet));
    }
}
}   // namespace chatroom