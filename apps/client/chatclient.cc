#include "chatclient.h"
#include "common/core/msg_id.h"
#include "common/core/packet.h"
#include "common/msgpb/register.pb.h"
#include "common/msgpb/login.pb.h"
#include "common/msgpb/add_friend.pb.h"
#include "common/msgpb/remove_friend.pb.h"
#include "common/msgpb/get_friends.pb.h"

#include "common/msgpb/register_ack.pb.h"
#include "common/msgpb/login_ack.pb.h"
#include "common/msgpb/add_friend_ack.pb.h"
#include "common/msgpb/remove_friend_ack.pb.h"
#include "common/msgpb/get_friends_ack.pb.h"

#include "tools/console.h"

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
    account_{0}
{
}


void ChatClient::Start() {
    socket_.connect(remote_ep_);
    RunLoop();
}

void ChatClient::RunLoop() {
    boost::asio::co_spawn(socket_.get_executor(), [this]()->boost::asio::awaitable<void> {
        try
        {
            while (co_await AskAccountAndPassword()) {
                assert(account_);
                co_await BasicPanel();
            }
        }
        catch(const std::exception& e)
        {
            console::PrintError("Error occur:{}\n", e.what());
            TipContinue();
        }
        
    }, boost::asio::detached);
}

boost::asio::awaitable<bool> ChatClient::AskAccountAndPassword() {
    auto opt = console::Options({"登录", "注册", "退出"});
    switch (opt)
    {
    case 0:     // 登录
    {
    re_login:
        console::Print("账号:"); auto account = console::GetUInt32();
        console::Print("密码:"); auto password = console::GetString();
        msgpb::Login login;
        login.set_account(account);
        login.set_password(password);
        co_await Send(msgid::kMsgLogin, login);
        auto ack = co_await Receive<msgpb::LoginAck>();
        if (ack.success()) {
            console::Print("登录成功!\n");
            account_ = account;
            user_name_ = ack.user_name();
            console::SetConsoleTitle(std::format("Chatroom App({})", user_name_));
        }
        else {
            console::PrintError("登录失败!原因:{}\n", ack.errmsg());
            goto re_login;
        }
        co_return true;
    }
    case 1:     // 注册
    {
    re_reg:
        console::Print("注册昵称:"); auto name = console::GetString();
    re_pwd:
        console::Print("注册密码:"); auto password = console::GetString();
        console::Print("确认密码:"); auto password2 = console::GetString();
        if (password != password2) {
            console::Print("两次密码不正确, 请重新输入!\n");
            goto re_pwd;
        }
        msgpb::Register reg;
        reg.set_name(name);
        reg.set_password(password);
        co_await Send(msgid::kMsgRegister, reg);
        auto ack = co_await Receive<msgpb::RegisterAck>();
        if (ack.success()) {
            console::Print("注册成功! 你的账号是:{}\n", ack.account());
            TipBack();
            goto re_login;
        }
        else {
            console::PrintError("注册失败! 原因:{}\n", ack.errmsg());
            TipRetry();
            goto re_reg;
        }
        co_return true;
    }
    default:
        co_return false;
    }
}

boost::asio::awaitable<void> ChatClient::BasicPanel() {
re_panel:
    auto idx = console::Options({"查看个人信息", "查看好友列表", "查看群组列表", "添加好友", "删除好友", "添加群组", "删除群组", "退出登录"});
    switch (idx)
    {
    case 0:     // 查看个人信息
    {

        goto re_panel;
    }
    case 1:     // 查看好友列表
    {
        msgpb::GetFriends msg;
        msg.set_user_id(account_);
        co_await Send(msgid::kMsgGetFriends, msg);
        auto ack = co_await Receive<msgpb::GetFriendsAck>();
        if (ack.success()) {
            if (ack.friends_info_size()) {
                std::vector<std::string> opts;
                for (auto &info : ack.friends_info()) {
                    opts.push_back(std::format("{}({})", info.name(), info.id()));
                }
                bool is_esc = false;
                auto idx = console::Options(opts, "[好友列表(按下Enter选择聊天, 按下Esc回退上一级)]", 0, &is_esc);
                if (is_esc) {
                    goto re_panel;
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
        goto re_panel;
    }
    case 2:     // 查看群组列表
    {

        goto re_panel;
    }
    case 3:     // 添加好友
    {
    re_add_friend:
        console::Print("输入要添加的好友账号:"); auto account = console::GetUInt32();
        msgpb::AddFriend msg;
        msg.set_user_id(account_);
        msg.set_friend_id(account);
        co_await Send(msgid::kMsgAddFriend, msg);
        auto ack = co_await Receive<msgpb::AddFriendAck>();
        if (ack.success()) {
            console::Print("好友添加成功!\n");
            TipBack();
        }
        else {
            console::PrintError("好友添加失败! 原因: {}\n", ack.errmsg());
            TipRetry();
            goto re_add_friend;
        }
        goto re_panel;
    }
    case 4:     // 删除好友
    {
    re_remove_friend:
        console::Print("输入要删除的好友账号:"); auto account = console::GetUInt32();
        msgpb::RemoveFriend msg;
        msg.set_user_id(account_);
        msg.set_friend_id(account);
        co_await Send(msgid::kMsgRemoveFriend, msg);
        auto ack = co_await Receive<msgpb::RemoveFriendAck>();
        if (ack.success()) {
            console::Print("好友删除成功!\n");
            TipBack();
        }
        else {
            console::PrintError("好友删除失败! 原因: {}\n", ack.errmsg());
            TipRetry();
            goto re_remove_friend;
        }
        goto re_panel;
    }
    case 5:     // 添加群组
    {

        goto re_panel;
    }
    case 6:     // 删除群组
    {

        goto re_panel;
    }
    default:    // 退出登录
        account_ = 0;
        break;
    }
}

boost::asio::awaitable<size_t> ChatClient::Send(uint16_t msgid, const google::protobuf::Message &msg) {
    SendPacket packet{msgid, msg};
    auto n = co_await boost::asio::async_write(socket_, boost::asio::buffer(packet.Pack()), boost::asio::use_awaitable);
    co_return n;
}

boost::asio::awaitable<RecvPacket> ChatClient::InternalReceive() {
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
    co_return recv_packet;
}
}   // namespace chatroom