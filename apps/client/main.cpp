#include "chatclient.h"
#include "common/core/config.h"
#include "tools/console.h"

int main() {
    try {
        boost::asio::io_service ios;
        chatroom::ChatClient client{ios, chatroom::kRemoteAddress, chatroom::kPortNum};
        client.Start();
    }
    catch (const std::exception& ex) {
        console::Print("Error occur:{}", ex.what());
    }
}