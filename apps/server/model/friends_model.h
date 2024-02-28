#include <vector>

namespace chatroom {
namespace model {
void InsertFriend(int user_id, int friend_id);
void RemoveFriend(int user_id, int friend_id);
std::vector<int> QueryFriends(int user_id);
}
}