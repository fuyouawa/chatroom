#include "chatclient.h"
#include "common/core/msg_id.h"
#include "common/core/packet.h"
#include "common/msgpb/user_register.pb.h"
#include "common/msgpb/user_register_ack.pb.h"
#include "common/msgpb/user_login.pb.h"
#include "common/msgpb/user_login_ack.pb.h"
#include "tools/console.h"

namespace chatroom {
ChatClient::ChatClient(boost::asio::io_service& ios, std::string_view remote_address, uint16_t port)
    : socket_{ios},
    remote_ep_{boost::asio::ip::address::from_string(remote_address.data()), port},
    account_{0}
{
}


void ChatClient::Start() {
    socket_.connect(remote_ep_);
    RunLoop();
}

void ChatClient::RunLoop() {
    boost::asio::co_spawn(socket_.get_executor(), [this]()->boost::asio::awaitable<void> {
        co_await AskAccountAndPassword();
    }, boost::asio::detached);
}

boost::asio::awaitable<void> ChatClient::AskAccountAndPassword() {
    auto opt = console::Options({"登录", "注册"}, 0);
    if (opt == 0) {
    re_login:
        console::Print("账号:"); auto account = console::GetUInt32();
        console::Print("密码:"); auto password = console::GetString();
        message::UserLogin login;
        login.set_account(account);
        login.set_password(password);
        co_await Send(MessageID::kUserLogin, login);
        auto recv = co_await Receive();
        auto ack = recv.DeserializeData<message::UserLoginAck>();
        if (ack.success()) {
            console::Print("登录成功!\n");
        }
        else {
            console::Print("登录失败!原因:{}\n", ack.errmsg());
            goto re_login;
        }
    }
    else {
    re_reg:
        console::Print("注册昵称:"); auto name = console::GetString();
    re_pwd:
        console::Print("注册密码:"); auto password = console::GetString();
        console::Print("确认密码:"); auto password2 = console::GetString();
        if (password != password2) {
            console::Print("两次密码不正确, 请重新输入!\n");
            goto re_pwd;
        }
        message::UserRegister reg;
        reg.set_name(name);
        reg.set_password(password);
        co_await Send(MessageID::kUserRegister, reg);
        auto recv = co_await Receive();
        auto ack = recv.DeserializeData<message::UserRegisterAck>();
        if (ack.success()) {
            console::Print("注册成功! 你的账号是:{}\n", ack.account());
        }
        else {
            console::Print("注册失败! 原因:{}\n", ack.errmsg());
            goto re_reg;
        }
    }
}

boost::asio::awaitable<size_t> ChatClient::Send(MessageID msgid, const google::protobuf::Message &msg) {
    SendPacket packet{msgid, msg};
    auto n = co_await boost::asio::async_write(socket_, boost::asio::buffer(packet.Pack()), boost::asio::use_awaitable);
    co_return n;
}

boost::asio::awaitable<RecvPacket> ChatClient::Receive() {
    PacketHeader network_header;
    auto n = co_await boost::asio::async_read(
        socket_,
        boost::asio::buffer(&network_header, sizeof(network_header)),
        boost::asio::use_awaitable);
    if (n == 0)
        throw boost::system::system_error(boost::asio::error::eof);
    assert(n == sizeof(network_header));
    RecvPacket recv_packet{network_header};

    n = co_await boost::asio::async_read(
        socket_,
        boost::asio::buffer(recv_packet.data(), recv_packet.data_size()),
        boost::asio::use_awaitable);
    if (n == 0)
        throw boost::system::system_error(boost::asio::error::eof);
    assert(n == recv_packet.data_size());
    co_return recv_packet;
}
}   // namespace chatroom