#include <iostream>
#include <utility>
#include <boost/asio.hpp>
#include "public.h"
#include "model/User.pb.h"
#include "tools/packet.h"

using namespace boost::asio::ip;
using namespace chatroom;

int main() {

	try {
		//创建上下文服务
		boost::asio::io_context   ioc;
		//构造endpoint
		tcp::endpoint remote_ep(address::from_string(kServerIp), kPort);
		tcp::socket sock(ioc);
		boost::system::error_code error = boost::asio::error::host_not_found;
		sock.connect(remote_ep, error);
		if (error) {
			std::cout << "connect failed, code is " << error.value() << " error msg is " << error.message();
			return 0;
		}

        std::cout << "连接成功, 是否开始发送" << std::endl;
        getchar();
        
        model::User user;
        user.set_name("测试名称");
        user.set_password("测试密码");
		boost::asio::write(sock, boost::asio::buffer(SendPacket(kLoginMsg, user).Pack()));

		getchar();
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}