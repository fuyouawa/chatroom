#pragma once
#include <chrono>

namespace chatroom
{
class Converter
{
public:
    static std::string ToString(const std::chrono::system_clock::time_point& tp, std::string_view fmt);
    static std::chrono::system_clock::time_point StringToTimepoint(std::string_view str, std::string_view fmt);
};
}