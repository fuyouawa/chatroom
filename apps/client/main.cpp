#include "chatclient.h"
#include "common/core/config.h"
#include <iostream>
#include "tools/console.h"

int main() {
/*    try {
        boost::asio::io_service ios;
        chatroom::ChatClient client{ios, chatroom::kRemoteAddress, chatroom::kPortNum};
        client.Start();
    }
    catch (const std::exception& ex) {
        std::cout << "Error occur: " << ex.what() << std::endl;
    }*/
    console::Options({"123", "3333", "5555"}, 0);
}