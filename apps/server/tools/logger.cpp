#include "logger.h"

namespace chatroom
{
void Logger::set_ostream(Level lv, std::ostream& outer) {
    auto [lvstr, _] = out_manager_[lv];
    out_manager_[lv] = {lvstr, &outer};
}

Logger::Logger(Level lv, std::string_view description)
    : Logger{lv, description, "", "", 0}
{
}

Logger::Logger(Level lv, std::string_view description, std::string_view filename, std::string_view func_name, size_t line)
    : lv_{lv}
{
    auto [lvstr, _] = out_manager_[lv];
    message_ = std::format("({:%F %R})[{}]-> {}", std::chrono::system_clock::now(), lvstr, description);
    if (!filename.empty()) {
        message_ += std::format(" 'at {}:{}({})'", filename, line, func_name);
        return;
    }
}

void Logger::Print() {
    auto [_, outer] = out_manager_[lv_];
    *outer << message_ << std::endl;
    switch (lv_)
    {
    case kFatal:
        abort();
        break;
    default:
        break;
    }
}
}