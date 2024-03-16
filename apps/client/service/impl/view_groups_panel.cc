#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/get_joined_groups.pb.h"
#include "common/msgpb/get_joined_groups_ack.pb.h"
#include "common/msgpb/quit_group.pb.h"
#include "common/msgpb/quit_group_ack.pb.h"
#include "common/core/msg_id.h"

namespace chatroom {
boost::asio::awaitable<void> ChatClient::ViewGroupsPanel() {
    msgpb::GetJoinedGroups msg;
    while(true) {
        console::Clear();
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
                    break;
                }
                auto& select_group = ack.groups_info()[idx];
                idx = console::Options(
                    {"进入聊天", "查看信息", "退出群聊"},
                    std::format("当前选中的群是:{}(Enter选中, Esc回退上一级)", select_group.name()),
                    0, &is_esc);
                if (is_esc) {
                    continue;
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
                    co_await QuitGroup(select_group.id());
                    TipBack();
                    continue;
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
        break;
    }
}


boost::asio::awaitable<void> ChatClient::QuitGroup(uint32_t group_id) {
    msgpb::QuitGroup msg;
    msg.set_user_id(user_id_);
    msg.set_group_id(group_id);
    co_await Send(msgid::kMsgQuitGroup, msg);
    auto ack = co_await Receive<msgpb::QuitGroupAck>(msgid::kMsgQuitGroupAck);
    if (ack.success()) {
        console::Print("群组删除成功!\n");
    }
    else {
        console::PrintError("群组删除失败! 原因: {}\n", ack.errmsg());
    }
}
}   // namespace chatroom