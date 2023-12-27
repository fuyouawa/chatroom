#include "converter.h"
#include <strstream>
#include <iomanip>
#include <time.h>

namespace chatroom
{
std::string Converter::ToString(const std::chrono::system_clock::time_point& tp, std::string_view fmt) {
    auto time = std::chrono::system_clock::to_time_t(tp);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), fmt.data());
    return ss.str();
}
std::chrono::system_clock::time_point Converter::StringToTimepoint(std::string_view str, std::string_view fmt) {
    std::stringstream ss;
    ss << str;
    std::tm parsed_time;
    ss >> std::get_time(&parsed_time, fmt.data());
    return std::chrono::system_clock::from_time_t(std::mktime(&parsed_time));
}
}