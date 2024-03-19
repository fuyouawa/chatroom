#include "model/group.h"
#include "tools/mysql.h"
#include "common/core/enums.h"

namespace chatroom {
namespace model {
int CreateGroup(uint32_t owner_user_id, std::string_view group_name) {
    auto res = mysql::Update("INSERT INTO `AllGroup`(`owner_user_id`,`name`) VALUES({},'{}')", owner_user_id, group_name);
    assert(res);
    auto group_id = mysql::GetLastInsertId();
    JoinGroup(owner_user_id, group_id, kGroupMaster);
    return group_id;
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

void JoinGroup(uint32_t user_id, uint32_t group_id, int privilege) {
    auto res = mysql::Update("INSERT INTO `GroupMember`(`group_id`,`user_id`,`user_privilege`) VALUES({},{},{})",
                                group_id, user_id, privilege);
    assert(res);
}

namespace {
uint32_t GetGroupMaster(uint32_t group_id) {
    auto res = mysql::Query("SELECT owner_user_id FROM `AllGroup` WHERE `id` = {}", group_id);
    auto suc = res->next(); assert(suc);
    return res->getUInt(1);
}

void RemoveGroup(uint32_t group_id) {
    auto res = mysql::Update("DELETE FROM `AllGroup` WHERE `id` = {}", group_id);
    assert(res);
    auto res2 = mysql::Update("DELETE FROM `GroupMember` WHERE `group_id`={}", group_id);
    assert(res2);
}
}


void QuitGroup(uint32_t user_id, uint32_t group_id) {
    if (GetGroupMaster(group_id) == user_id) {
        RemoveGroup(group_id);
    }
    else {
        auto res = mysql::Update("DELETE FROM `GroupMember` WHERE `group_id`={} AND `user_id`={}", group_id, user_id);
        assert(res);
    }
}


std::string GetGroupName(uint32_t group_id) {
    auto res = mysql::Query("SELECT name FROM `AllGroup` WHERE `id` = {}", group_id);
    bool suc = res->next(); assert(suc);
    return res->getString(1);
}


std::vector<GroupMemberBasicInfo> GetGroupMembers(uint32_t group_id) {
    std::vector<GroupMemberBasicInfo> total;
    auto res = mysql::Query("SELECT * FROM `GroupMember` WHERE `group_id` = {}", group_id);
    while (res->next()) {
        total.push_back({res->getUInt(2), res->getInt(3)});
    }
    return total;
}

void SaveGroupMessage(uint32_t user_id, uint32_t group_id, std::string_view msg) {
    
}
}
}