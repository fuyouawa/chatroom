#pragma once
#include <boost/asio.hpp>

namespace chatroom
{
using IOService = boost::asio::io_service;
using Socket = boost::asio::ip::tcp::socket;
using Acceptor = boost::asio::ip::tcp::acceptor;
}