#include <vector>
#include <cstdint>
#include <string_view>
#include <google/protobuf/repeated_field.h>

namespace chatroom {
namespace model {
void InsertFriend(uint32_t user_id, uint32_t friend_id);
void RemoveFriend(uint32_t user_id, uint32_t friend_id);
std::vector<uint32_t> QueryFriends(uint32_t user_id);

void SaveFriendMessage(uint32_t user_id, uint32_t friend_id, std::string_view msg);
void ClearFriendMessages(uint32_t user_id, uint32_t friend_id);
google::protobuf::RepeatedPtrField<std::string> GetFriendMessages(uint32_t user_id, uint32_t friend_id);
}   // namespace model
}   // namespace chatroom