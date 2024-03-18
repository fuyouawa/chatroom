#include <string>
#include <vector>
#include <cstdint>

namespace chatroom {
namespace model {
struct GroupInfo {
    uint32_t id;
    std::string name;
};

struct GroupMemberBasicInfo {
    uint32_t id;
    int privilege;
};

int InsertGroup(uint32_t owner_user_id, std::string_view group_name);
GroupInfo QueryGroup(uint32_t group_id);
std::vector<uint32_t> GetJoinedGroups(uint32_t user_id);
void JoinGroup(uint32_t user_id, uint32_t group_id);
void QuitGroup(uint32_t user_id, uint32_t group_id);

std::string GetGroupName(uint32_t group_id);
std::vector<GroupMemberBasicInfo> GetGroupMembers(uint32_t group_id);
}
}