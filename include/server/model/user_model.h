#pragma once
#include <chrono>
#include <expected>
#include <cppconn/exception.h>
#include <initializer_list>
#include "user.h"

namespace chatroom
{
class UserModel
{
public:
    static auto Insert(const User& user) -> std::expected<uint, sql::SQLException>;
    static auto Query(uint account) -> std::expected<User, sql::SQLException>;
    static bool Remove(std::initializer_list<uint> accounts);
};
}