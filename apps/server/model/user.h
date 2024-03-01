#pragma once
#include <chrono>
#include <initializer_list>
#include <optional>

namespace chatroom {
namespace model {
struct UserInfo {
    int id;
    std::string name;
    std::string password;
    bool online;
};

int InsertUser(const UserInfo& user);
UserInfo QueryUser(int id);
void UpdateUser(const UserInfo& user);
void UpdateUserOnline(int id, bool b);
void RemoveUser(std::initializer_list<int> users_id);
}   // namespace model
}   // namespace chatroom