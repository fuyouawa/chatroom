#include <format>

namespace chatroom
{
template<typename... Args>
[[nodiscard]] inline std::string MakeFormat(std::string_view fmt, Args&&... args)
{
    if constexpr (sizeof...(args) == 0) {
        return fmt;
    }
    else {
        return std::vformat(fmt, std::make_format_args(args...))
    }
}
}