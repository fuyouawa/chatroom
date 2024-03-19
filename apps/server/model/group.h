#include <string>
#include <vector>
#include <cstdint>

#include "common/datapb/group_member.pb.h"
#include <google/protobuf/repeated_field.h>

namespace chatroom {
namespace model {
struct GroupInfo {
    uint32_t id;
    std::string name;
};

int CreateGroup(uint32_t owner_user_id, std::string_view group_name);
GroupInfo QueryGroup(uint32_t group_id);
std::vector<uint32_t> GetJoinedGroups(uint32_t user_id);
void JoinGroup(uint32_t user_id, uint32_t group_id, int privilege);
void QuitGroup(uint32_t user_id, uint32_t group_id);

std::string GetGroupName(uint32_t group_id);
google::protobuf::RepeatedPtrField<datapb::GroupMember> GetGroupMembers(uint32_t group_id);

void SaveGroupMessage(uint32_t user_id, uint32_t group_id, std::string_view msg);
}
}