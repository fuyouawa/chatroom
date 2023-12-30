#pragma once
#include <utility>
#include <boost/asio.hpp>
#include <string>
#include <mutex>
#include <queue>
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

    void Start();
    void Close();

    void Send(uint16_t msg_type, const google::protobuf::Message& data);

    auto& socket() { return socket_; }
    auto uuid() { return uuid_; }
    void set_close_callback(CloseCallback cb) { close_callback_ = std::move(cb); }
    void set_read_callback(ReadCallback cb) { read_callback_ = std::move(cb); }

private:
    void HandleWrited(const boost::system::error_code& ec);

    bool is_closed_;
    Socket socket_;
    ChatServer* server_;
    std::string uuid_;
    std::mutex mutex_;
    std::queue<std::shared_ptr<SendPacket>> send_queue_;
    CloseCallback close_callback_;
    ReadCallback read_callback_;
};
}