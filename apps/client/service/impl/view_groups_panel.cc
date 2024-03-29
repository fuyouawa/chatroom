#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/get_joined_groups.pb.h"
#include "common/msgpb/get_joined_groups_ack.pb.h"
#include "common/msgpb/quit_group.pb.h"
#include "common/msgpb/quit_group_ack.pb.h"
#include "common/msgpb/get_group_info.pb.h"
#include "common/msgpb/get_group_info_ack.pb.h"
#include "common/msgpb/send_msg_to_group.pb.h"
#include "common/msgpb/send_msg_to_group_ack.pb.h"
#include "common/msgpb/get_msgs_from_group.pb.h"
#include "common/msgpb/get_msgs_from_group_ack.pb.h"
#include "common/core/msg_id.h"
#include "common/core/enums.h"

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
            group_opt_panel:
                idx = console::Options(
                    {"发送群聊消息", "查看群聊消息", "查看群组信息", "退出群聊"},
                    std::format("当前选中的群是:{}(Enter选中, Esc回退上一级)", select_group.name()),
                    0, &is_esc);
                if (is_esc) {
                    continue;
                }
                switch (idx)
                {
                case 0:     // 发送群聊消息
                    co_await SendMsgToGroupPanel(select_group.id(), select_group.name());
                    goto group_opt_panel;
                case 1:     // 查看群聊消息
                    co_await GetMsgFromGroupPanel(select_group.id(), select_group.name());
                    goto group_opt_panel;
                case 2:     // 查看信息
                    co_await GetGroupInfoPanel(select_group.id());
                    goto group_opt_panel;
                default:    // 退出群聊
                    co_await QuitGroup(select_group.id());
                    TipBack();
                    continue;
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
        console::Print("群组退出成功!\n");
    }
    else {
        console::PrintError("群组退出失败! 原因: {}\n", ack.errmsg());
    }
}

boost::asio::awaitable<void> ChatClient::SendMsgToGroupPanel(uint32_t group_id, std::string_view group_name) {
    console::Clear();
    msgpb::SendMsgToGroup msg;
    while (true) {
        console::Print("[在群组\"{}\"({})中发送消息]\n", group_name, group_id);
        console::Print("->"); auto input = console::GetString();
        if (input.empty() || input.size() > 200) {
            console::PrintError("消息不能为空或者超过200字!\n");
            continue;
        }
        msg.set_user_id(user_id_);
        msg.set_group_id(group_id);
        msg.set_msg(input);
        co_await Send(msgid::kMsgSendMsgToGroup, msg);
        auto ack = co_await Receive<msgpb::SendMsgToGroupAck>(msgid::kMsgSendMsgToGroupAck);
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

boost::asio::awaitable<void> ChatClient::GetMsgFromGroupPanel(uint32_t group_id, std::string_view group_name) {
    console::Clear();
    console::Print("[与{}({})的聊天记录]\n", group_name, group_id);
    msgpb::GetMsgsFromGroup msg;
    msg.set_group_id(group_id);
    co_await Send(msgid::kMsgGetMsgFromGroup, msg);
    auto ack = co_await Receive<msgpb::GetMsgsFromGroupAck>(msgid::kMsgGetMsgFromGroupAck);
    if (ack.success()) {
        if (ack.msgs_size() == 0) {
            console::Print("暂无聊天记录\n");
        }
        else {
            for (auto &msg : ack.msgs()) {
                console::Print("[{}({})] -> {}\n", msg.user_name(), msg.user_id(), msg.msg());
            }
        }
    }
    else {
        console::PrintError("消息获取失败! 原因:{}\n", ack.errmsg());
    }
    TipBack();
}

boost::asio::awaitable<void> ChatClient::GetGroupInfoPanel(uint32_t group_id) {
    console::Clear();
    msgpb::GetGroupInfo msg;
    msg.set_group_id(group_id);
    co_await Send(msgid::kMsgGetGroupInfo, msg);
    auto ack = co_await Receive<msgpb::GetGroupInfoAck>(msgid::kMsgGetGroupInfoAck);
    if (ack.success()) {
        console::Print("[基础信息]\n");
        console::Print("群名称:{}\n", ack.group_name());
        console::Print("群id:{}\n", group_id);
        console::Print("成员人数:{}\n\n", ack.members_info_size());
        console::Print("[成员列表]\n");
        size_t i = 1;
        for (auto &mem : ack.members_info()) {
            std::string_view privilege_str;
            switch (mem.privilege())
            {
            case kGroupMaster:
                privilege_str = "群主";
                break;
            default:
                privilege_str = "成员";
                break;
            }
            console::Print("{}.{}({}) - {}\n", i, mem.name(), mem.id(), privilege_str);
        }
    }
    else {
        console::PrintError("群组信息获取失败! 原因: {}\n", ack.errmsg());
    }
    console::Print("\n");
    TipBack();
}
}   // namespace chatroom