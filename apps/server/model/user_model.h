#pragma once
#include <chrono>
#include <expected>
#include <cppconn/exception.h>
#include <initializer_list>
#include <optional>
#include "model/user.h"

namespace chatroom
{
class UserModel
{
public:
    static auto Insert(const User& user) -> std::expected<uint, sql::SQLException>;
    static auto Query(uint account) -> std::expected<User, sql::SQLException>;
    static auto Update(const User& user) -> std::optional<sql::SQLException>;
    static auto UpdateState(uint account, UserState state) -> std::optional<sql::SQLException>;
    static auto Remove(std::initializer_list<uint> accounts) -> std::optional<sql::SQLException>;
};
}