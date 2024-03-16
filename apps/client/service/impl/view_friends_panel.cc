#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/get_friends.pb.h"
#include "common/msgpb/get_friends_ack.pb.h"
#include "common/msgpb/remove_friend.pb.h"
#include "common/msgpb/remove_friend_ack.pb.h"
#include "common/core/msg_id.h"

namespace chatroom {
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
                    co_await SendMsgToFriendPanel(select_friend.id());
                    continue;
                case 1:     // 查看对方消息
                    co_await GetMsgFromFriendPanel(select_friend.id());
                    continue;
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

boost::asio::awaitable<void> ChatClient::SendMsgToFriendPanel(uint32_t friend_id) {

}

boost::asio::awaitable<void> ChatClient::GetMsgFromFriendPanel(uint32_t friend_id) {

}
}   // namespace chatroom