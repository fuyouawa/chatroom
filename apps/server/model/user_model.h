#pragma once
#include <chrono>
#include <initializer_list>
#include <optional>
#include "model/user.h"

namespace chatroom {
namespace model {
uint InsertUser(const User& user);
User QueryUser(uint account);
void UpdateUser(const User& user);
void UpdateUserState(uint account, UserState state);
void RemoveUser(std::initializer_list<uint> accounts);
}
}