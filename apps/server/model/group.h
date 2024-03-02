#include <string_view>
#include <vector>
#include <cstdint>

namespace chatroom {
namespace model {
enum GroupPrivilege {
    kGroupMaster,
    kGroupMember
};

int InsertGroup(uint32_t owner_user_id, std::string_view group_name);
void RemoveGroup(uint32_t owner_user_id, uint32_t group_id);
std::vector<uint32_t> GetJoinedGroups(uint32_t user_id);
void JoinGroup(uint32_t user_id, uint32_t group_id);
void QuitGroup(uint32_t user_id, uint32_t group_id);
}
}