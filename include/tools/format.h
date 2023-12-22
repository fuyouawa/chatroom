#pragma once
#include <format>
#include <utility>
#include <boost/asio.hpp>

namespace chatroom
{
template<typename... Args>
[[nodiscard]] inline std::string FormatString(std::string_view fmt, Args&&... args)
{
    if constexpr (sizeof...(args) == 0) {
        return fmt.data();
    }
    else {
        return std::vformat(fmt, std::make_format_args(args...));
    }
}
}

template<>
struct std::formatter<boost::asio::ip::tcp::endpoint> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const boost::asio::ip::tcp::endpoint& ep, FormatContext& ctx) const {
        return std::format_to(ctx.out(), "{}:{}", ep.address().to_string(), ep.port());
    }
};