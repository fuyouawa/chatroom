#pragma once
#include <chrono>
#include <optional>
#include "user.h"

namespace chatroom
{
class UserModel
{
public:
    static std::optional<uint> Insert(const User& user);
    static std::optional<User> Query(uint account);
};
}