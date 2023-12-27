#include <iostream>
#include <csignal>
#include "server/chatserver.h"
#include "config.h"

int main()
{
    try
    {
        boost::asio::io_service ios;
        chatroom::ChatServer server{ios, chatroom::kPortNum};
        server.Start();

		boost::asio::signal_set signals(ios, SIGINT, SIGTERM);
		signals.async_wait([&](auto, auto) {
			ios.stop();
		});
        
        ios.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}