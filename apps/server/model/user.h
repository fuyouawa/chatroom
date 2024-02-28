#pragma once
#include <chrono>

namespace chatroom {
enum class UserState: int { kOffline, kOnline };

class User
{
public:
    User() : account_{0}, state_{UserState::kOffline} {}

    auto account() const noexcept { return account_; }
    auto register_time() const noexcept { return register_time_; }
    auto name() const noexcept { return name_; }
    auto password() const noexcept { return password_; }
    auto state() const noexcept { return state_; }

    void set_account(int account) noexcept { account_ = account; }
    void set_register_time(const std::chrono::system_clock::time_point& register_time) { register_time_ = register_time; }
    void set_name(std::string_view name) { name_ = name; }
    void set_password(std::string_view password) { password_ = password; }
    void set_state(UserState state) noexcept { state_ = state; }

private:
    uint account_;
    std::chrono::system_clock::time_point register_time_;
    std::string name_;
    std::string password_;
    UserState state_;
};
}

template<>
struct std::formatter<chatroom::UserState> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(chatroom::UserState state, FormatContext& ctx) const {
        return std::format_to(ctx.out(), "{}", static_cast<uint16_t>(state));
    }
};