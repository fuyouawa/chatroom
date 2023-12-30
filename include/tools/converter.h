#pragma once
#include <chrono>
#include <google/protobuf/timestamp.pb.h>

namespace chatroom
{
class Converter
{
public:
    using time_point = std::chrono::system_clock::time_point;

    static std::string ToString(const time_point& tp, std::string_view fmt);
    static time_point ToTimepoint(std::string_view str, std::string_view fmt);
    static time_point ToTimepoint(const google::protobuf::Timestamp& timestamp);
    static google::protobuf::Timestamp ToTimestamp(const time_point& tp);
};
}