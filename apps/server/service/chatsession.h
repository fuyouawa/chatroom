#pragma once
#include <utility>
#include <boost/asio.hpp>
#include <string>
#include <mutex>
#include <queue>
#include <atomic>
#include <functional>
#include "model/user.h"

#include "common/core/packet.h"
#include "common/core/noncopyable.h"

namespace chatroom {
class ChatSession;
class ChatServer;
using ChatSessionPtr = std::shared_ptr<ChatSession>;
using CloseCallback = std::function<void(ChatSessionPtr)>;
using ReadCallback = std::function<void(ChatSessionPtr, const RecvPacket&)>;

class ChatSession : public std::enable_shared_from_this<ChatSession>, NonCopyable 
{
public:
    using Socket = boost::asio::ip::tcp::socket;

    static constexpr int kMaxSendQueue = 1000;

    ChatSession(Socket&& socket, ChatServer* server);
    ~ChatSession();

    void Start();
    void Close();

    void Send(uint16_t msgid, const google::protobuf::Message& data);

    auto& socket() const { return socket_; }
    auto client_ep() const { return socket_.remote_endpoint(); }
    auto uuid() const { return uuid_; }
    auto user_id() const { return user_id_; }
    auto logging() const { return logging_; }
    auto is_closed() const { return is_closed_.load(); }
    void set_close_callback(CloseCallback&& cb) { close_callback_ = std::move(cb); }
    void set_read_callback(ReadCallback&& cb) { read_callback_ = std::move(cb); }
    void set_user_id(uint32_t user_id) { user_id_ = user_id; }
    void set_logging(bool logging) { logging_ = logging; }
    //TODO 超时关闭连接功能

private:
    void HandleWrited(const boost::system::error_code& ec);

    bool logging_;
    uint32_t user_id_;
    std::atomic_bool is_closed_;
    Socket socket_;
    ChatServer* server_;
    std::string uuid_;
    std::mutex mutex_;
    std::queue<std::shared_ptr<SendPacket>> send_queue_;
    CloseCallback close_callback_;
    ReadCallback read_callback_;
};
}   // namespace chatroom