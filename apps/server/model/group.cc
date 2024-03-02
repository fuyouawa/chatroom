#include "model/group.h"
#include "tools/mysql.h"

namespace chatroom {
namespace model {
int InsertGroup(uint32_t owner_user_id, std::string_view group_name) {
    auto res = mysql::Update("INSERT INTO `AllGroup`(`owner_user_id`,`name`) VALUES({},'{}')", owner_user_id, group_name);
    assert(res);
    auto group_id = mysql::GetLastInsertId();
    auto res2 = mysql::Update("INSERT INTO `GroupMember`(`group_id`,`user_id`,`user_privilege`) VALUES({},{},{})",
                                group_id, owner_user_id, static_cast<int>(kGroupMaster));
    assert(res2);
    return group_id;
}

void RemoveGroup(uint32_t owner_user_id, uint32_t group_id) {
    auto res = mysql::Update("DELETE FROM `AllGroup` WHERE `id` = {} AND `owner_user_id` = {}", group_id, owner_user_id);
    assert(res);
    auto res2 = mysql::Update("DELETE FROM `GroupMember` WHERE `group_id`={}", group_id);
    assert(res2);
}

GroupInfo QueryGroup(uint32_t group_id) {
    auto res = mysql::Query("SELECT * FROM `AllGroup` WHERE `id` = {}", group_id);
    res->next();
    return GroupInfo{
        .id = res->getUInt("id"),
        .name = res->getString("name")
    };
}

std::vector<uint32_t> GetJoinedGroups(uint32_t user_id) {
    auto res = mysql::Query("SELECT group_id FROM `GroupMember` WHERE `user_id` = {}", user_id);
    std::vector<uint32_t> total;
    while (res->next()) {
        total.push_back(res->getUInt(1));
    }
    return total;
}

void JoinGroup(uint32_t user_id, uint32_t group_id) {
    auto res = mysql::Update("INSERT INTO `GroupMember`(`group_id`,`user_id`,`user_privilege`) VALUES({},{},{})",
                                group_id, user_id, static_cast<int>(kGroupMember));
    assert(res);
}

void QuitGroup(uint32_t user_id, uint32_t group_id) {

}
}
}