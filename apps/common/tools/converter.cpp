#include "converter.h"
#include <sstream>
#include <iomanip>
#include <time.h>

namespace chatroom {
namespace converter {
std::string ToString(const time_point& tp, std::string_view fmt) {
    const auto time = std::chrono::system_clock::to_time_t(tp);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), fmt.data());
    return ss.str();
}

time_point ToTimepoint(std::string_view str, std::string_view fmt) {
    std::stringstream ss;
    ss << str;
    std::tm parsed_time;
    ss >> std::get_time(&parsed_time, fmt.data());
    return std::chrono::system_clock::from_time_t(std::mktime(&parsed_time));
}

time_point ToTimepoint(const google::protobuf::Timestamp& timestamp) {
    const std::chrono::seconds seconds(timestamp.seconds());
    const std::chrono::nanoseconds nanos(timestamp.nanos());
    return time_point(std::chrono::duration_cast<std::chrono::system_clock::duration>(seconds + nanos));
}

google::protobuf::Timestamp ToTimestamp(const time_point& tp) {
    const auto duration = tp.time_since_epoch();
    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    const auto nanos = duration - seconds;

    google::protobuf::Timestamp timestamp;
    timestamp.set_seconds(seconds.count());
    timestamp.set_nanos(nanos.count());
    return timestamp;
}
}
}