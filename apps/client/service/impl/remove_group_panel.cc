#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/remove_group.pb.h"
#include "common/msgpb/remove_group_ack.pb.h"
#include "common/core/msg_id.h"

namespace chatroom {
boost::asio::awaitable<void> ChatClient::RemoveGroupPanel() {
    while (true) {
        console::Print("输入要删除的群组ID:"); auto group_id = console::GetUInt32();
        msgpb::RemoveGroup msg;
        msg.set_user_id(user_id_);
        msg.set_group_id(group_id);
        co_await Send(msgid::kMsgRemoveGroup, msg);
        auto ack = co_await Receive<msgpb::RemoveGroupAck>(msgid::kMsgRemoveGroupAck);
        if (ack.success()) {
            console::Print("群组删除成功!\n");
            TipBack();
            break;
        }
        else {
            console::PrintError("群组删除失败! 原因: {}\n", ack.errmsg());
            TipRetry();
        }
    }
}
}   // namespace chatroom