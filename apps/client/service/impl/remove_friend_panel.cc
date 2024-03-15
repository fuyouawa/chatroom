#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/remove_friend.pb.h"
#include "common/msgpb/remove_friend_ack.pb.h"
#include "common/core/msg_id.h"

namespace chatroom {
boost::asio::awaitable<void> ChatClient::RemoveFriendPanel() {
    while(true) {
        console::Print("输入要删除的好友账号:"); auto user_id = console::GetUInt32();
        msgpb::RemoveFriend msg;
        msg.set_user_id(user_id_);
        msg.set_friend_id(user_id);
        co_await Send(msgid::kMsgRemoveFriend, msg);
        auto ack = co_await Receive<msgpb::RemoveFriendAck>(msgid::kMsgRemoveFriendAck);
        if (ack.success()) {
            console::Print("好友删除成功!\n");
            TipBack();
            break;
        }
        else {
            console::PrintError("好友删除失败! 原因: {}\n", ack.errmsg());
            TipRetry();
        }
    }
}
}   // namespace chatroom