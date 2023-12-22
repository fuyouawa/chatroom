#include "logger.h"

namespace chatroom
{
void Logger::set_ostream(Level lv, std::ostream& outer) {
    auto [lvstr, _] = out_manager_[lv];
    out_manager_[lv] = {lvstr, &outer};
}

Logger::Logger(Level lv, std::string_view description)
    : lv_{lv}
{
    auto [lvstr, _] = out_manager_[lv];
    message_ = std::format("[{}] {}", lvstr, description);
}

Logger::Logger(Level lv, std::string_view description, std::string_view filename, std::string_view func_name, size_t line)
    : lv_{lv}
{
    auto [lvstr, _] = out_manager_[lv];
    if (lv == kDebug) {
        message_ = std::format("[{}] {}:{}({}): {}", lvstr, filename, line, func_name, description);
        return;
    }
    message_ = std::format("[{}] {}", lvstr, description);
}

void Logger::Print() {
    auto [_, outer] = out_manager_[lv_];
    *outer << message_;
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