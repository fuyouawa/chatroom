#include "model/friends_model.h"
#include "tools/mysql.h"

namespace chatroom {
namespace model {
void InsertFriend(int user_id, int friend_id) {
    auto res = mysql::Update("INSERT INTO Friends (user_id, friend_id) VALUES ({}, {})", user_id, friend_id);
    assert(res);
}

void RemoveFriend(int user_id, int friend_id) {
    auto res = mysql::Update("DELETE FROM Friends WHERE user_id = {} AND friend_id = {}", user_id, friend_id);
    assert(res);
}

std::vector<int> QueryFriends(int user_id) {
    std::vector<int> total;
    auto res = mysql::Query("SELECT friend_id FROM Friends WHERE user_id = {}", user_id);
    while (res->next()) {
        total.push_back(res->getInt(0));
    }
    return total;
}
}
}