#pragma once
#include <string_view>
#include <utility>
#include <boost/asio.hpp>
#include <google/protobuf/message.h>
#include <list>
#include "common/core/packet.h"

namespace chatroom {
class ChatClient {
public:
    ChatClient(boost::asio::io_service& ios, std::string_view remote_address, uint16_t port);

    void Start();

private:
    void RunLoop();

    boost::asio::awaitable<bool> AskUserIdAndPassword();
    boost::asio::awaitable<void> BasicPanel();

    boost::asio::awaitable<size_t> Send(uint16_t msgid, const google::protobuf::Message& msg);
    boost::asio::awaitable<RecvPacket> InternalReceive(uint16_t msgid);

    template<ConvertiableToMessage T>
    boost::asio::awaitable<T> Receive(uint16_t msgid) {
        const RecvPacket recv = co_await InternalReceive(msgid);
        co_return recv.DeserializeData<T>();
    }

    boost::asio::awaitable<void> ReceiveLoop();

    boost::asio::awaitable<void> LoginPanel();
    boost::asio::awaitable<void> RegisterPanel();

    boost::asio::awaitable<void> ViewPersonalInfoPanel();
    boost::asio::awaitable<void> ViewFriendsPanel();
    boost::asio::awaitable<void> ViewGroupsPanel();
    boost::asio::awaitable<void> AddFriendPanel();
    boost::asio::awaitable<void> CreateGroupPanel();
    boost::asio::awaitable<void> JoinGroupPanel();
    boost::asio::awaitable<void> SendMsgToFriendPanel(uint32_t friend_id, std::string_view friend_name);
    boost::asio::awaitable<void> GetMsgFromFriendPanel(uint32_t friend_id, std::string_view friend_name);

    boost::asio::awaitable<void> RemoveFriend(uint32_t friend_id);
    boost::asio::awaitable<void> QuitGroup(uint32_t group_id);

    void Done();

    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::endpoint remote_ep_;
    uint32_t user_id_;
    std::string user_name_;
    int cur_msgid_;
    std::list<RecvPacket> recv_packets_list_;
    bool done_;
};
}   // namespace chatroom
