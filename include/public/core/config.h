#pragma once
#include <utility>
#include <boost/asio.hpp>

namespace chatroom
{
constexpr int kPortNum = 8888;

constexpr const char* kDbHostName = "tcp://127.0.0.1:3306";
constexpr const char* kDbUserName = "root";
constexpr const char* kDbPassword = "X290714/";
constexpr const char* kDbCatalog = "chatroom";
}