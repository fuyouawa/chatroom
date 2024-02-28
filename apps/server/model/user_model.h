#pragma once
#include <chrono>
#include <initializer_list>
#include <optional>
#include "model/user.h"

namespace chatroom
{
class UserModel
{
public:
    static uint Insert(const User& user);
    static User Query(uint account);
    static void Update(const User& user);
    static void UpdateState(uint account, UserState state);
    static void Remove(std::initializer_list<uint> accounts);
};
}