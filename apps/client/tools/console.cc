#include "console.h"
#include <conio.h>
#include <cassert>
#include <stack>
#include <iostream>

namespace console {
void Print(std::string_view fmt) {
    std::cout << fmt;
}

int Options(std::initializer_list<std::string_view> opts, int cur_selection) {
re_print:
    Clear();
    size_t i = 0;
    for (const auto& opt : opts) {
        bool is_selection = cur_selection == i;
        if (is_selection) {
            BeginColor(Color::Green);
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
        default:
            goto get_input;
    }
    return cur_selection;
}

Keycode InputKey() {
    int k = _getch();
    switch (k) {
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
        default:
            assert(false);
    }
    return Keycode::W;
}
void Clear() {
    std::system("cls");
}

#include <Windows.h>
namespace {
std::stack<WORD> attr_stack_;
}   // namespace

void BeginColor(Color color) {
    HANDLE console_handler = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(console_handler, &info);
    attr_stack_.push(info.wAttributes);
    int color_attr = 0;
    switch (color) {
        case Color::Green:
            color_attr = FOREGROUND_GREEN;
            break;
        case Color::White:
            color_attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
    }
    SetConsoleTextAttribute(console_handler, color_attr);
}

void EndColor() {
    assert(!attr_stack_.empty());
    HANDLE console_handler = GetStdHandle(STD_OUTPUT_HANDLE);
    auto attr = attr_stack_.top();
    attr_stack_.pop();
    SetConsoleTextAttribute(console_handler, attr);
}

namespace {
template<typename T>
T GetValue() {
    T tmp;
    std::cin >> tmp;
    return tmp;
}
}   // namespace

std::string GetString() {
    return GetValue<std::string>();
}
uint32_t GetUInt32() {
    return GetValue<uint32_t>();
}
}   // namespace console