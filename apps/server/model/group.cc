#include "model/group.h"
#include "tools/mysql.h"
#include "common/core/enums.h"
#include "model/user.h"

#include "common/datapb/group_messages.pb.h"

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


google::protobuf::RepeatedPtrField<datapb::GroupMember> GetGroupMembers(uint32_t group_id) {
    google::protobuf::RepeatedPtrField<datapb::GroupMember> total;
    auto res = mysql::Query("SELECT user_id, user_privilege FROM `GroupMember` WHERE `group_id` = {}", group_id);
    while (res->next()) {
        auto elem = total.Add();
        elem->set_id(res->getUInt(1));
        elem->set_name(model::GetUserInfo(elem->id()).name);
        elem->set_privilege(res->getInt(2));
    }
    return total;
}


namespace {
const size_t kGroupMsgsCapacity = 256;

int FindFreeOrCreateGroupMessage(uint32_t group_id, size_t msg_size) {
    const auto needed_size = msg_size + 8;
    assert(needed_size <= kGroupMsgsCapacity);
    auto res = mysql::Query("SELECT id FROM `GroupMessages` WHERE group_id = {} AND res_size >= {}", group_id, needed_size);
    if (res->next()) {
        return res->getUInt(1);
    }
    else {
        datapb::GroupMessages grp_msgs{};
        auto suc = mysql::Update("INSERT INTO `GroupMessages` (group_id, msgs, res_size) VALUES ({}, '{}', {})",
                                group_id,
                                grp_msgs.SerializeAsString(),
                                kGroupMsgsCapacity - grp_msgs.ByteSizeLong());
        assert(suc);
        return mysql::GetLastInsertId();
    }
}
}   // namespace

void SaveGroupMessage(uint32_t user_id, uint32_t group_id, std::string_view msg) {
    std::string trans_msg;
    for (auto &ch : msg) {
        if (ch == '\'')
            trans_msg += "\\'";
        else
            trans_msg += ch;
    }
    
    auto stor_id = FindFreeOrCreateGroupMessage(group_id, trans_msg.size());
    auto res = mysql::Query("SELECT msgs, res_size FROM `GroupMessages` WHERE id = {}", stor_id);
    res->next();
    auto res_size = res->getUInt(2);

    datapb::GroupMessages grp_msgs;
    grp_msgs.ParseFromString(res->getString(1).asStdString());
    assert(kGroupMsgsCapacity - res_size == grp_msgs.ByteSizeLong());
    auto elem = grp_msgs.add_msgs();
    elem->set_user_id(user_id);
    elem->set_msg(msg.data());
    mysql::Update("UPDATE `GroupMessages` SET `msgs`='{}', res_size={} WHERE `id`={}",
                grp_msgs.SerializeAsString(),
                kGroupMsgsCapacity - grp_msgs.ByteSizeLong(),
                stor_id);
}
}
}