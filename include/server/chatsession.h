#pragma once
#include <utility>
#include <boost/asio.hpp>
#include <string>
#include <mutex>
#include <deque>
#include <atomic>
#include <functional>
#include "base/basic.h"
#include "base/usings.h"
#include "tools/packet.h"

namespace chatroom
{
class ChatSession;
class ChatServer;
using ChatSessionPtr = std::shared_ptr<ChatSession>;
using CloseCallback = std::move_only_function<void(ChatSessionPtr)>;
using ReadCallback = std::move_only_function<void(ChatSessionPtr, const RecvPacket&)>;

class ChatSession : public std::enable_shared_from_this<ChatSession>
{
public:
    static constexpr int kMaxSendQueue = 1000;

    ChatSession(Socket&& socket, ChatServer* server);
    ~ChatSession() noexcept;

    void Start();
    void Terminate() noexcept;

    void Send(uint16_t msg_type, const google::protobuf::Message& data);
    void SendEmergency(int event_id, std::string_view extras="");

    auto& socket() const noexcept { return socket_; }
    auto uuid() noexcept { return uuid_; }
    auto account() noexcept { return account_; }
    auto is_closed() const noexcept { return is_closed_.load(); }
    void set_close_callback(CloseCallback cb) noexcept { close_callback_ = std::move(cb); }
    void set_read_callback(ReadCallback cb) noexcept { read_callback_ = std::move(cb); }
    void set_account(uint account) noexcept { account_ = account; }

private:
    void HandleWrited(const boost::system::error_code& ec);
    void Send(uint16_t msg_type, const google::protobuf::Message& data, bool is_emergency);

    uint account_;
    std::atomic_bool is_closed_;
    Socket socket_;
    ChatServer* server_;
    std::string uuid_;
    std::mutex mutex_;
    std::deque<std::shared_ptr<SendPacket>> send_deque_;
    CloseCallback close_callback_;
    ReadCallback read_callback_;
};
}