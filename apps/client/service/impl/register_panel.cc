#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/register.pb.h"
#include "common/msgpb/register_ack.pb.h"
#include "common/core/msg_id.h"

namespace chatroom {
boost::asio::awaitable<void> ChatClient::RegisterPanel() {
    msgpb::Register reg;
    std::string password;
    while (true) {
        console::Clear();
        console::Print("注册昵称:"); auto name = console::GetString();
        while (true) {
            console::Print("注册密码:"); password = console::GetString();
            console::Print("确认密码:"); auto password2 = console::GetString();
            if (password != password2) {
                console::Print("两次密码不正确, 请重新输入!\n");
                continue;
            }
            break;
        }
        reg.set_name(name);
        reg.set_password(password);
        co_await Send(msgid::kMsgRegister, reg);
        auto ack = co_await Receive<msgpb::RegisterAck>(msgid::kMsgRegisterAck);
        if (ack.success()) {
            console::Print("注册成功! 你的账号是:{}\n", ack.user_id());
            TipBack();
            break;
        }
        else {
            console::PrintError("注册失败! 原因:{}\n", ack.errmsg());
            TipRetry();
        }
    }
}
}   // namespace chatroom