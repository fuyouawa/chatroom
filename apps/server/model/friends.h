#include <vector>
#include <cstdint>

namespace chatroom {
namespace model {
void InsertFriend(uint32_t user_id, uint32_t friend_id);
void RemoveFriend(uint32_t user_id, uint32_t friend_id);
std::vector<uint32_t> QueryFriends(uint32_t user_id);
}   // namespace model
}   // namespace chatroom