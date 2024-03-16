#include <vector>
#include <cstdint>
#include <string_view>

namespace chatroom {
namespace model {
void InsertFriend(uint32_t user_id, uint32_t friend_id);
void RemoveFriend(uint32_t user_id, uint32_t friend_id);
std::vector<uint32_t> QueryFriends(uint32_t user_id);

void TmpStorFriendMsg(uint32_t user_id, uint32_t friend_id, std::string_view msg);
std::vector<std::string> GetFriendMsgsTmp(uint32_t user_id, uint32_t friend_id);
int FindFreeFriendMsgsTmp(uint32_t user_id, uint32_t friend_id, size_t needed_size);
}   // namespace model
}   // namespace chatroom