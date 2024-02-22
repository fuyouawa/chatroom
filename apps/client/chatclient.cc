#include "chatclient.h"
#include "common/core/msg_id.h"
#include "common/core/packet.h"
#include "msgpb/user_register.pb.h"
#include "msgpb/user_login.pb.h"
#include "msgpb/user_login_ack.pb.h"
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
    auto opt = console::Options({"µ«¬º", "◊¢≤·"}, 0);
    if (opt == 0) {
    re_ask:
        console::Print("’Àªß:"); auto account = console::GetUInt32();
        console::Print("√‹¬Î:"); auto password = console::GetString();
        message::UserLogin login;
        login.set_account(account);
        login.set_password(password);
        co_await Send(MessageID::kUserLogin, login);
        auto recv = co_await Receive();
        auto ack = recv.DeserializeData<message::UserLoginAck>();
        if (!ack.success()) {
            console::Print("√‹¬Î¥ÌŒÛ, «Î÷ÿ–¬ ‰»Î!\n");
            goto re_ask;
        }
        else {
            console::Print("√‹¬Î’˝»∑, µ«¬º≥…π¶!\n");
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