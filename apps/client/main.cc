#include "chatclient.h"
#include "common/core/config.h"
#include "tools/console.h"
#include "common/datapb/friend_msgs_temp.pb.h"

int main() {
    try {
        console::SetConsoleTitle("Chatroom App");
        boost::asio::io_service ios;
        chatroom::ChatClient client{ios, chatroom::kRemoteAddress, chatroom::kPortNum};
        client.Start();
        ios.run();
    }
    catch (const std::exception& ex) {
        console::Print("Error occur:{}", ex.what());
    }
}