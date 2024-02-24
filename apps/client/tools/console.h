#pragma once
#include <format>
#include <initializer_list>
#include <cstdint>

namespace console {
enum class Keycode {
    W,
    A,
    S,
    D,
    Enter
};

enum class Color {
    kGreen,
    kWhite
};
void Print(std::string_view fmt);

template<typename... Args>
void Print(std::string_view fmt, Args&&... args) {
    Print(std::vformat(fmt, std::make_format_args(std::forward<Args>(args)...)));
}

std::string GetString();
uint32_t GetUInt32();

int Options(std::initializer_list<std::string_view> opts, size_t cur_selection);
Keycode InputKey();
void Clear();

void BeginColor(Color color);
void EndColor();
void ResetColor();
}   // namespace console