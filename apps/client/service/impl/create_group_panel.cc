#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/create_group.pb.h"
#include "common/msgpb/create_group_ack.pb.h"
#include "common/core/msg_id.h"

namespace chatroom {
boost::asio::awaitable<void> ChatClient::CreateGroupPanel() {
    while (true) {
        console::Print("输入要创建的群组名称:"); auto name = console::GetString();
        msgpb::CreateGroup msg;
        msg.set_user_id(user_id_);
        msg.set_group_name(name);
        co_await Send(msgid::kMsgCreateGroup, msg);
        auto ack = co_await Receive<msgpb::CreateGroupAck>(msgid::kMsgCreateGroupAck);
        if (ack.success()) {
            console::Print("群组创建成功! 群组ID:{}\n", ack.group_id());
            TipBack();
            break;
        }
        else {
            console::PrintError("群组创建失败! 原因: {}\n", ack.errmsg());
            TipRetry();
        }
    }   
}
}   // namespace chatroom