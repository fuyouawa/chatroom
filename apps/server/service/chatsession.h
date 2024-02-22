#pragma once
#include <utility>
#include <boost/asio.hpp>
#include <string>
#include <mutex>
#include <deque>
#include <atomic>
#include <functional>
#include "model/user.h"

#include "common/core/packet.h"
#include "common/core/noncopyable.h"
#include "common/core/msg_id.h"

namespace chatroom
{
class ChatSession;
class ChatServer;
using ChatSessionPtr = std::shared_ptr<ChatSession>;
using CloseCallback = std::move_only_function<void(ChatSessionPtr)>;
using ReadCallback = std::move_only_function<void(ChatSessionPtr, const RecvPacket&)>;

class ChatSession : public std::enable_shared_from_this<ChatSession>, NonCopyable
{
public:
    using Socket = boost::asio::ip::tcp::socket;

    static constexpr int kMaxSendQueue = 1000;

    ChatSession(Socket&& socket, ChatServer* server, std::string_view name);
    ~ChatSession() noexcept;

    void Start();
    void Close() noexcept;

    void Send(MessageID msgid, const google::protobuf::Message& data) noexcept;
    void SendEmergency(MessageID msgid, const google::protobuf::Message& data) noexcept;

    auto& socket() const noexcept { return socket_; }
    auto uuid() const noexcept { return uuid_; }
    auto name() const noexcept { return name_; }
    auto account() const noexcept { return account_; }
    auto logging() const noexcept { return logging_; }
    auto is_closed() const noexcept { return is_closed_.load(); }
    void set_close_callback(CloseCallback cb) noexcept { close_callback_ = std::move(cb); }
    void set_read_callback(ReadCallback cb) noexcept { read_callback_ = std::move(cb); }
    void set_account(uint account) noexcept { account_ = account; }
    void set_logging(bool logging) noexcept { logging_ = logging; }
    //TODO 超时关闭连接功能

private:
    void Send(MessageID msgid, const google::protobuf::Message& data, bool is_emergency) noexcept;
    void HandleWrited(const boost::system::error_code& ec);

    bool logging_;
    std::string name_;
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