#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/join_group.pb.h"
#include "common/msgpb/join_group_ack.pb.h"
#include "common/core/msg_id.h"

namespace chatroom {
boost::asio::awaitable<void> ChatClient::JoinGroupPanel() {
    msgpb::JoinGroup msg;
    while (true) {
        console::Clear();
        console::Print("输入要加入的群组ID:"); auto group_id = console::GetUInt32();
        msg.set_user_id(user_id_);
        msg.set_group_id(group_id);
        co_await Send(msgid::kMsgJoinGroup, msg);
        auto ack = co_await Receive<msgpb::JoinGroupAck>(msgid::kMsgJoinGroupAck);
        if (ack.success()) {
            console::Print("群组加入成功!\n");
            TipBack();
            break;
        }
        else {
            console::PrintError("群组加入失败! 原因: {}\n", ack.errmsg());
            TipRetry();
        }
    }
}
}   // namespace chatroom