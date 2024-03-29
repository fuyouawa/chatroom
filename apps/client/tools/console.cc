#include "console.h"
#include <cassert>
#include <stack>
#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <ranges>
#include <vector>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

namespace console {
namespace internal {
void Print(std::string_view fmt) {
    std::cout << fmt;
}
}   // namespace internal

int Options(const std::vector<std::string>& opts, std::string_view text, size_t cur_selection, bool* is_esc) {
re_print:
    Clear();
    if (!text.empty()) {
        Print("{}\n", text);
    }
    size_t i = 0;
    for (const auto& opt : opts) {
        bool is_selection = cur_selection == i;
        if (is_selection) {
            BeginColor(Color::kGreen);
        }
        Print("{} {}\n", is_selection ? ">>" : "  ", opt);
        if (is_selection) {
            EndColor();
        }
        ++i;
    }
get_input:
    switch (InputKey()) {
        case Keycode::W:
        {
            if (cur_selection > 0) {
                --cur_selection;
            }
            goto re_print;
        }
        case Keycode::S:
        {
            if (cur_selection < opts.size() - 1) {
                ++cur_selection;
            }
            goto re_print;
        }
        case Keycode::Enter:
            break;
        case Keycode::Esc:
            if (is_esc) {
                *is_esc = true;
                return 0;
            }
        default:
            goto get_input;
    }
    return cur_selection;
}

Keycode InputKey() {
    termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    char ch;
    std::cin.get(ch);
    
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    switch (ch) {
        case 'w':
        case 'W':
            return Keycode::W;
        case 'a':
        case 'A':
            return Keycode::A;
        case 's':
        case 'S':
            return Keycode::S;
        case 'd':
        case 'D':
            return Keycode::D;
        case '\n':
        case '\r':
            return Keycode::Enter;
        case 27:
            return Keycode::Esc;
        default:
            return Keycode::TODO;
    }
}


Keycode InputKey(std::initializer_list<Keycode> accept_keys) {
    Keycode input;
    do {
        input = InputKey();
    } while (std::ranges::find(accept_keys, input) == accept_keys.end());
    return input;
}


void Clear() {
    std::cout << "\033[2J\033[1;1H";
}

namespace {
std::string_view GetColorAnsi(Color color) {
    switch (color)
    {
    case Color::kRed:
        return "\x1b[31m";
    case Color::kGreen:
        return "\x1b[32m";
    case Color::kWhite:
        return "\x1b[37m";
    default:
        return "";
    }
}
std::stack<std::string_view> color_stack_;
}   // namespace


void BeginColor(Color color) {
    auto ansi = GetColorAnsi(color);
    color_stack_.push(ansi);
    std::cout << ansi;
}

void EndColor() {
    color_stack_.pop();
    if (color_stack_.empty()) {
        ResetColor();
    }
    else {
        std::cout << color_stack_.top();
        color_stack_.pop();
    }
}
void ResetColor() {
    std::cout << "\x1b[0m";
}

namespace {
template<typename T>
T GetValue() {
    T tmp;
    std::cin >> tmp;
    getchar();
    return tmp;
}
}   // namespace

std::string GetString() {
    return GetValue<std::string>();
}
uint32_t GetUInt32() {
    return GetValue<uint32_t>();
}


void SetConsoleTitle(std::string_view title) {
    std::cout << std::format("\033]0;{}\007", title) << std::endl;
}
}   // namespace console