#pragma once
#include <iostream>
#include <vector>
#include <boost/system/error_code.hpp>
#include "format.h"

namespace chatroom
{
class Logger
{
public:
    enum Level {
        kInfo,
        kDebug,
        kWarning,
        kError,
        kFatal
    };

    static void set_ostream(Level lv, std::ostream& outer);

    Logger(Level lv, std::string_view description);
    Logger(Level lv, std::string_view description, std::string_view filename, std::string_view func_name, size_t line);

    void Print();


private:
    static inline std::vector<std::tuple<std::string_view, std::ostream*>> out_manager_ = {
        {"Info", &std::cout},
        {"Debug", &std::clog},
        {"Warning", &std::cout},
        {"Error", &std::cerr},
        {"Fatal", &std::cerr}
    };

    std::string message_;
    Level lv_;
};
}

#define CHATROOM_LOG_INFO(...) \
    chatroom::Logger(chatroom::Logger::kInfo, FormatString(__VA_ARGS__)).Print();
#ifdef NDEBUG
#define CHATROOM_LOG_DEBUG(...)
#else
#define CHATROOM_LOG_DEBUG(...) \
    chatroom::Logger(chatroom::Logger::kDebug, FormatString(__VA_ARGS__), __FILE__, __func__, __LINE__).Print();
#endif
#define CHATROOM_LOG_WARNING(...) \
    chatroom::Logger(chatroom::Logger::kWarning, FormatString(__VA_ARGS__)).Print();
#define CHATROOM_LOG_ERROR(...) \
    chatroom::Logger(chatroom::Logger::kError, FormatString(__VA_ARGS__)).Print();
#define CHATROOM_LOG_FATAL(...) \
    chatroom::Logger(chatroom::Logger::kFatal, FormatString(__VA_ARGS__)).Print();
