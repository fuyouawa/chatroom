#include "model/group.h"
#include "tools/mysql.h"

namespace chatroom {
namespace model {
int InsertGroup(uint32_t owner_user_id, std::string_view group_name) {
    auto res = mysql::Update("INSERT INTO `AllGroup`(`owner_user_id`,`name`) VALUES({},'{}')", owner_user_id, group_name);
    assert(res);
    return mysql::GetLastInsertId();
}

void RemoveGroup(uint32_t owner_user_id, uint32_t group_id) {
    auto res = mysql::Update("DELETE FROM `AllGroup` WHERE `id` = {} AND `owner_user_id` = {}", group_id, owner_user_id);
    assert(res);
}

std::vector<uint32_t> GetJoinedGroups(uint32_t user_id) {

}
}
}