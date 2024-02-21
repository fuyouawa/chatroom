#pragma once
#include <format>
#include <iostream>
#include <initializer_list>

namespace console {
enum class Keycode {
    W,
    A,
    S,
    D,
    Enter
};

enum class Color {
    Green,
    White
};

template<typename... Args>
void Print(std::string_view fmt, Args&&... args) {
    std::cout << std::vformat(fmt, std::make_format_args(std::forward<Args>(args)...)) << std::endl;
}
int Options(std::initializer_list<std::string_view> opts, int cur_selection);
Keycode InputKey();
void Clear();

void BeginColor(Color color);
void EndColor();
}   // namespace console