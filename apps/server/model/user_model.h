#pragma once
#include <chrono>
#include <initializer_list>
#include <optional>
#include "model/user.h"

namespace chatroom {
namespace model {
int InsertUser(const User& user);
User QueryUser(int account);
void UpdateUser(const User& user);
void UpdateUserState(int account, UserState state);
void RemoveUser(std::initializer_list<int> accounts);
}
}