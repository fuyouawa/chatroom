#include <iostream>
#include <csignal>
#include "server/base/ioservice_pool.h"
#include "server/chatserver.h"

int main()
{
    try
    {
        boost::asio::io_service ios;
        auto& pool = chatroom::IOServicePool::instance();
        pool.Start();
        chatroom::ChatServer server{ios, 8888};
        server.Start();

		boost::asio::signal_set signals(ios, SIGINT, SIGTERM);
		signals.async_wait([&](auto, auto) {
			ios.stop();
            pool.Stop();
		});
        
        ios.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}