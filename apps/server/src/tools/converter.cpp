#include "converter.h"
#include <sstream>
#include <iomanip>
#include <time.h>

namespace chatroom
{
std::string Converter::ToString(const Converter::time_point& tp, std::string_view fmt) {
    auto time = std::chrono::system_clock::to_time_t(tp);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), fmt.data());
    return ss.str();
}
Converter::time_point Converter::ToTimepoint(std::string_view str, std::string_view fmt) {
    std::stringstream ss;
    ss << str;
    std::tm parsed_time;
    ss >> std::get_time(&parsed_time, fmt.data());
    return std::chrono::system_clock::from_time_t(std::mktime(&parsed_time));
}

Converter::time_point Converter::ToTimepoint(const google::protobuf::Timestamp& timestamp) {
    std::chrono::seconds seconds(timestamp.seconds());
    std::chrono::nanoseconds nanos(timestamp.nanos());
    return Converter::time_point(seconds + nanos);
}

google::protobuf::Timestamp Converter::ToTimestamp(const Converter::time_point& tp) {
    auto duration = tp.time_since_epoch();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    auto nanos = duration - seconds;

    google::protobuf::Timestamp timestamp;
    timestamp.set_seconds(seconds.count());
    timestamp.set_nanos(nanos.count());
    return timestamp;
}
}