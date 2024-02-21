#include "chatclient.h"
#include "common/core/msg_id.h"
#include "common/core/packet.h"
#include "msgpb/user_register.pb.h"
#include "msgpb/user_login.pb.h"

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

}

void ChatClient::AskAccountAndPassword() {

}
}   // namespace chatroom