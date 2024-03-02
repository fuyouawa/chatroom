#include <string_view>
#include <vector>
#include <cstdint>

namespace chatroom {
namespace model {
int InsertGroup(uint32_t owner_user_id, std::string_view group_name);
void RemoveGroup(uint32_t owner_user_id, uint32_t group_id);
std::vector<uint32_t> GetJoinedGroups(uint32_t user_id);
}
}