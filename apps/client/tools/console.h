#pragma once
#include <format>
#include <span>
#include <cstdint>
#include <initializer_list>

namespace console {
enum class Keycode {
    W,
    A,
    S,
    D,
    Enter,
    Esc,
    TODO,
};

enum class Color {
    kGreen,
    kWhite,
    kRed,
};

namespace internal {
void Print(std::string_view fmt);
}   // namespace internal

std::string GetString();
uint32_t GetUInt32();

void SetConsoleTitle(std::string_view title);

Keycode InputKey();
void Clear();

void BeginColor(Color color);
void EndColor();
void ResetColor();


int Options(std::span<const std::string_view> opts, size_t cur_selection=0, bool* is_esc=nullptr);
int Options(std::initializer_list<std::string_view> opts, size_t cur_selection=0, bool* is_esc=nullptr);

template<typename... Args>
void Print(std::string_view fmt, Args&&... args) {
    internal::Print(std::vformat(fmt, std::make_format_args(std::forward<Args>(args)...)));
}

template<typename... Args>
void PrintError(std::string_view fmt, Args&&... args) {
    BeginColor(Color::kRed);
    Print(fmt, std::forward<Args>(args)...);
    EndColor();
}
}   // namespace console