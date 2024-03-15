#include "chatclient.h"
#include "service/utils.h"
#include "tools/console.h"
#include "common/msgpb/login.pb.h"
#include "common/msgpb/login_ack.pb.h"
#include "common/core/msg_id.h"

namespace chatroom {
boost::asio::awaitable<void> ChatClient::LoginPanel() {
    msgpb::Login login;
    while (true) {
        console::Clear();
        console::Print("账号:"); auto user_id = console::GetUInt32();
        console::Print("密码:"); auto password = console::GetString();
        login.set_user_id(user_id);
        login.set_password(password);
        co_await Send(msgid::kMsgLogin, login);
        auto ack = co_await Receive<msgpb::LoginAck>(msgid::kMsgLoginAck);
        if (ack.success()) {
            console::Print("登录成功!\n");
            user_id_ = user_id;
            user_name_ = ack.user_name();
            console::SetConsoleTitle(std::format("Chatroom App({})", user_name_));
            break;
        }
        else {
            console::PrintError("登录失败!原因:{}\n", ack.errmsg());
        }
    }
}
}   // namespace chatroom