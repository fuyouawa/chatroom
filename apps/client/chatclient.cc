#include "chatclient.h"
#include "tools/console.h"

#include <chrono>

using namespace std::chrono_literals;

namespace chatroom {
ChatClient::ChatClient(boost::asio::io_service& ios, std::string_view remote_address, uint16_t port)
    : socket_{ios},
    remote_ep_{boost::asio::ip::address::from_string(remote_address.data()), port},
    user_id_{0}
{
}

void ChatClient::Done() {
    user_id_ = 0;
    done_ = true;
    socket_.close();
}

void ChatClient::Start() {
    socket_.connect(remote_ep_);
    RunLoop();
}

void ChatClient::RunLoop() {
    boost::asio::co_spawn(socket_.get_executor(), [this]{ return BasicPanel(); }, boost::asio::detached);
    boost::asio::co_spawn(socket_.get_executor(), [this]{ return ReceiveLoop(); }, boost::asio::detached);
}

boost::asio::awaitable<void> ChatClient::BasicPanel() {
    try
    {
    beg:
        do {
            auto opt = console::Options({"登录", "注册", "退出"});
            switch (opt)
            {
            case 0:     // 登录
                co_await LoginPanel();
                break;
            case 1:     // 注册
                co_await RegisterPanel();
                break;
            default:    // 退出
                co_return;
            }
        }
        while (user_id_ == 0);

        while (!done_) {
            auto idx = console::Options({"查看好友列表", "查看群组列表", "添加好友", "创建群组", "加入群组", "退出登录"});
            switch (idx)
            {
            case 0:     // 查看好友列表
                co_await ViewFriendsPanel();
                break;
            case 1:     // 查看群组列表
                co_await ViewGroupsPanel();
                break;
            case 2:     // 添加好友
                co_await AddFriendPanel();
                break;
            case 3:     // 创建群组
                co_await CreateGroupPanel();
                break;
            case 4:     // 加入群组
                co_await JoinGroupPanel();
                break;
            default:    // 退出登录
                Done();
                break;
            }
        }
        goto beg;
    }
    catch(const std::exception& e)
    {
        console::PrintError("Error occur:{}\n", e.what());
    }
}

boost::asio::awaitable<size_t> ChatClient::Send(uint16_t msgid, const google::protobuf::Message &msg) {
    SendPacket packet{msgid, msg};
    auto n = co_await boost::asio::async_write(socket_, boost::asio::buffer(packet.Pack()), boost::asio::use_awaitable);
    co_return n;
}

boost::asio::awaitable<RecvPacket> ChatClient::InternalReceive(uint16_t msgid) {
    auto exec = socket_.get_executor();
    boost::asio::steady_timer delayer{exec, 100ms};
    while (true)
    {
        assert(!done_);
        bool found = false;
        auto iter = recv_packets_list_.begin();
        for (;iter != recv_packets_list_.end(); ++iter) {
            if (iter->msgid() == msgid) {
                found = true;
                break;
            }
        }
        if (found) {
            auto tmp = std::move(*iter);
            recv_packets_list_.erase(iter);
            co_return std::move(tmp);
        }
        co_await delayer.async_wait(boost::asio::use_awaitable);
    }
}


boost::asio::awaitable<void> ChatClient::ReceiveLoop() {
    while (!done_) {
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

        recv_packets_list_.push_back(std::move(recv_packet));
    }
}
}   // namespace chatroom