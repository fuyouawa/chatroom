#include <iostream>
#include <utility>
#include <boost/asio.hpp>
#include "config.h"
#include "public.h"
#include "message/login.pb.h"
#include "message/register.pb.h"
#include "message/register_ack.pb.h"
#include "tools/packet.h"
#include "tools/converter.h"

using namespace boost::asio::ip;
using namespace chatroom;

int main() {

	try {
		//创建上下文服务
		boost::asio::io_context   ioc;
		tcp::socket sock(ioc);
		boost::system::error_code error = boost::asio::error::host_not_found;
		sock.connect(kRemoteEndpoint, error);
		if (error) {
			std::cout << "connect failed, code is " << error.value() << " error msg is " << error.message();
			return 0;
		}

        std::cout << "连接成功, 是否开始发送" << std::endl;
        getchar();
        
        message::Register reg;
        reg.set_name("TestName");
        reg.set_password("TestPwd");
		reg.mutable_register_time()->CopyFrom(Converter::ToTimestamp(std::chrono::system_clock::now()));
		boost::asio::write(sock, boost::asio::buffer(SendPacket(kRegisterMsg, reg).Pack()));
		
		PacketHeader header;
		boost::asio::read(sock, boost::asio::buffer(&header, sizeof(header)));
		RecvPacket recv{header};
		boost::asio::read(sock, boost::asio::buffer(recv.data(), recv.data_size()));
		auto v = recv.DeserializeData<message::RegisterAck>();
		if (v.success())
			std::cout << "Success! account:" << v.account() << std::endl;
		getchar();
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}