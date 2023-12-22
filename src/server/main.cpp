#include <iostream>
#include "server/chatserver.h"

int main()
{
    try
    {
        boost::asio::io_service ios;
        chatroom::ChatServer server{ios, 8888};
        server.Start();
        ios.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}