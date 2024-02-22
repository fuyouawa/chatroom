#pragma once
#include <chrono>
#include <google/protobuf/timestamp.pb.h>

namespace chatroom {
namespace converter {
using time_point = std::chrono::system_clock::time_point;
std::string ToString(const time_point& tp, std::string_view fmt);
time_point ToTimepoint(std::string_view str, std::string_view fmt);
time_point ToTimepoint(const google::protobuf::Timestamp& timestamp);
google::protobuf::Timestamp ToTimestamp(const time_point& tp);
}
}