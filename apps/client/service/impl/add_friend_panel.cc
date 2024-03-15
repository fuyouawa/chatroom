#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/add_friend.pb.h"
#include "common/msgpb/add_friend_ack.pb.h"
#include "common/core/msg_id.h"

namespace chatroom {
boost::asio::awaitable<void> ChatClient::AddFriendPanel() {
    while(true) {
        console::Print("输入要添加的好友账号:"); auto user_id = console::GetUInt32();
        msgpb::AddFriend msg;
        msg.set_user_id(user_id_);
        msg.set_friend_id(user_id);
        co_await Send(msgid::kMsgAddFriend, msg);
        auto ack = co_await Receive<msgpb::AddFriendAck>(msgid::kMsgAddFriendAck);
        if (ack.success()) {
            console::Print("好友添加成功!\n");
            TipBack();
            break;
        }
        else {
            console::PrintError("好友添加失败! 原因: {}\n", ack.errmsg());
            TipRetry();
        }
    }
}
}   // namespace chatroom