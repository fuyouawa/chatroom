#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/get_friends.pb.h"
#include "common/msgpb/get_friends_ack.pb.h"
#include "common/msgpb/remove_friend.pb.h"
#include "common/msgpb/remove_friend_ack.pb.h"
#include "common/msgpb/send_msg_to_friend.pb.h"
#include "common/msgpb/send_msg_to_friend_ack.pb.h"
#include "common/msgpb/get_msgs_from_friend.pb.h"
#include "common/msgpb/get_msgs_from_friend_ack.pb.h"
#include "common/core/msg_id.h"

namespace chatroom {
//TODO 显示在线状态
boost::asio::awaitable<void> ChatClient::ViewFriendsPanel() {
    msgpb::GetFriends msg;
    while (true) {
        console::Clear();
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
                    co_return;
                }
                auto& select_friend = ack.friends_info()[idx];
            friend_opt_panel:
                idx = console::Options(
                    {"发送消息", "查看对方消息", "删除好友"},
                    std::format("当前选中的好友是:{}(Enter选中, Esc回退上一级)", select_friend.name()),
                    0, &is_esc);
                if (is_esc) {
                    continue;
                }
                switch (idx)
                {
                case 0:     // 发送消息
                    co_await SendMsgToFriendPanel(select_friend.id(), select_friend.name());
                    goto friend_opt_panel;
                case 1:     // 查看对方消息
                    co_await GetMsgFromFriendPanel(select_friend.id(), select_friend.name());
                    goto friend_opt_panel;
                default:    // 删除好友
                    co_await RemoveFriend(select_friend.id());
                    TipBack();
                    continue;
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
        break;
    }
}

boost::asio::awaitable<void> ChatClient::RemoveFriend(uint32_t friend_id) {
    msgpb::RemoveFriend msg;
    msg.set_user_id(user_id_);
    msg.set_friend_id(friend_id);
    co_await Send(msgid::kMsgRemoveFriend, msg);
    auto ack = co_await Receive<msgpb::RemoveFriendAck>(msgid::kMsgRemoveFriendAck);
    if (ack.success()) {
        console::Print("好友删除成功!\n");
    }
    else {
        console::PrintError("好友删除失败! 原因: {}\n", ack.errmsg());
    }
}

// TODO 输入空格会出问题
boost::asio::awaitable<void> ChatClient::SendMsgToFriendPanel(uint32_t friend_id, std::string_view friend_name) {
    console::Clear();
    msgpb::SendMsgToFriend msg;
    while (true) {
        console::Print("[发送消息给\"{}\"({})]\n", friend_name, friend_id);
        console::Print("->"); auto input = console::GetString();
        if (input.empty() || input.size() > 200) {
            console::PrintError("消息不能为空或者超过200字!\n");
            continue;
        }
        msg.set_user_id(user_id_);
        msg.set_friend_id(friend_id);
        msg.set_msg(input);
        co_await Send(msgid::kMsgSendMsgToFriend, msg);
        auto ack = co_await Receive<msgpb::SendMsgToFriendAck>(msgid::kMsgSendMsgToFriendAck);
        if (ack.success()) {
            console::Print("消息发送成功!(按Enter继续, 或者Esc退出聊天)\n");
            if (console::InputKey({Keycode::Enter, Keycode::Esc}) == Keycode::Enter) {
                console::Clear();
                continue;
            }
            break;
        }
        else {
            console::PrintError("消息发送失败! 原因:{}\n", ack.errmsg());
            TipBack();
            break;
        }
    }
}

boost::asio::awaitable<void> ChatClient::GetMsgFromFriendPanel(uint32_t friend_id, std::string_view friend_name) {
    console::Clear();
    console::Print("[与{}({})的聊天记录]\n", friend_name, friend_id);
    msgpb::GetMsgsFromFriend msg;
    msg.set_user_id(user_id_);
    msg.set_friend_id(friend_id);
    co_await Send(msgid::kMsgGetMsgFromFriend, msg);
    auto ack = co_await Receive<msgpb::GetMsgsFromFriendAck>(msgid::kMsgGetMsgFromFriendAck);
    if (ack.success()) {
        if (ack.msgs_size() == 0) {
            console::Print("暂无聊天记录\n");
        }
        else {
            for (auto &msg : ack.msgs()) {
                console::Print("-> {}\n", msg);
            }
        }
    }
    else {
        console::PrintError("消息获取失败! 原因:{}\n", ack.errmsg());
    }
    TipBack();
}
}   // namespace chatroom