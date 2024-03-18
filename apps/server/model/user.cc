#include "model/user.h"
#include "tools/mysql.h"

namespace chatroom {
namespace model {
int InsertUser(const UserInfo& user) {
    auto res = mysql::Update("INSERT INTO `User`(name,password,online) VALUES('{}','{}',{})",
        user.name, user.password, user.online);
    assert(res);
    return mysql::GetLastInsertId();
}

UserInfo QueryUser(uint32_t id) {
    auto res = mysql::Query("SELECT * FROM User WHERE id = {}", id);
    res->next();
    return UserInfo{
        .id = id,
        .name = res->getString("name"),
        .password = res->getString("password"),
        .online = res->getBoolean("online")};
}

void UpdateUser(const UserInfo& user) {
    auto res = mysql::Update(
        "UPDATE `User` SET name='{}',password='{}',online={} WHERE `id`={}",
        user.name, user.password, user.online, user.id);
    assert(res);
}

void UpdateUserOnline(uint32_t id, bool b) {
    auto res = mysql::Update("UPDATE `User` SET online={} WHERE `id`={}", b, id);
    assert(res);
}

void RemoveUser(std::initializer_list<int> users_id) {
    auto res = mysql::Update("DELETE FROM `User` WHERE `id` IN ({:`, `<>})", users_id);
    assert(res);
}


void OfflineAll() {
    mysql::Update("UPDATE `User` SET online=0");
}
}   // namespace model
}   // namespace chatroom