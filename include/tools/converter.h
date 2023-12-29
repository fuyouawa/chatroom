#pragma once
#include <chrono>
#include <google/protobuf/timestamp.pb.h>

namespace chatroom
{
class Converter
{
public:
    static std::string ToString(const std::chrono::system_clock::time_point& tp, std::string_view fmt);
    static std::chrono::system_clock::time_point TimepointCast(std::string_view str, std::string_view fmt);
    static std::chrono::system_clock::time_point TimepointCast(const google::protobuf::Timestamp& timestamp);
};
}