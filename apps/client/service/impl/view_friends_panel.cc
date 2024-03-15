#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/get_friends.pb.h"
#include "common/msgpb/get_friends_ack.pb.h"
#include "common/core/msg_id.h"

namespace chatroom {
boost::asio::awaitable<void> ChatClient::ViewFriendsPanel() {
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
                co_return;
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
}
}   // namespace chatroom