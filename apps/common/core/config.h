#pragma once
#include <cstdint>

namespace chatroom {
constexpr uint16_t kPortNum = 8888;
constexpr const char* kRemoteAddress = "127.0.0.1";

constexpr const char* kDbHostName = "tcp://127.0.0.1:3306";
constexpr const char* kDbUserName = "root";
constexpr const char* kDbPassword = "X290714/";
constexpr const char* kDbCatalog = "chatroom";
}   // namespace chatroom