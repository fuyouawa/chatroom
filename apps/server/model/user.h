#pragma once
#include <chrono>
#include <initializer_list>
#include <optional>
#include <cstdint>

namespace chatroom {
namespace model {
struct UserInfo {
    uint32_t id;
    std::string name;
    std::string password;
    bool online;
};

int InsertUser(const UserInfo& user);
UserInfo QueryUser(uint32_t id);
void UpdateUser(const UserInfo& user);
void UpdateUserOnline(uint32_t id, bool b);
void RemoveUser(std::initializer_list<int> users_id);

void OfflineAll();
}   // namespace model
}   // namespace chatroom