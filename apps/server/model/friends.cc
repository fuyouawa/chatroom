#include "model/friends.h"
#include "tools/mysql.h"
#include "common/msgpb/friend_msgs_temp.pb.h"
#include <ranges>

namespace chatroom {
namespace model {
void InsertFriend(uint32_t user_id, uint32_t friend_id) {
    auto res = mysql::Update("INSERT INTO `Friends` (user_id, friend_id) VALUES ({}, {})", user_id, friend_id);
    assert(res);
}

void RemoveFriend(uint32_t user_id, uint32_t friend_id) {
    auto res = mysql::Update("DELETE FROM `Friends` \
                              WHERE (user_id = {} AND friend_id = {}) \
                                 OR (user_id = {} AND friend_id = {})", user_id, friend_id, friend_id, user_id);
    assert(res);
}

std::vector<uint32_t> QueryFriends(uint32_t user_id) {
    std::vector<uint32_t> total;
    auto res = mysql::Query("SELECT friend_id FROM `Friends` WHERE user_id = {}", user_id);
    auto res2 = mysql::Query("SELECT user_id FROM `Friends` WHERE friend_id = {}", user_id);
    while (res->next()) {
        total.push_back(res->getUInt(1));
    }
    while (res2->next()) {
        total.push_back(res2->getUInt(1));
    }
    return total;
}

void TmpStorFriendMsg(uint32_t user_id, uint32_t friend_id, std::string_view msg) {

}

std::vector<std::string> GetFriendMsgsTmp(uint32_t user_id, uint32_t friend_id) {
    auto res = mysql::Query("SELECT msgs FROM `FriendsMsgsTemp` WHERE user_id = {} friend_id = {}", user_id, friend_id);
    std::vector<std::string> total;
    while (res->next()) {
        auto msgs_str = res->getString(1);
        msgpb::FriendMsgsTemp msgs_tmp;
        msgs_tmp.ParseFromString(msgs_str.asStdString());
        auto origin_total_end = total.end();
        total.resize(total.size() + msgs_tmp.msgs_size());
        std::ranges::move(std::move(msgs_tmp.msgs()), origin_total_end);
    }
    return total;
}


int FindFreeFriendMsgsTmp(uint32_t user_id, uint32_t friend_id, size_t needed_size) {
    auto res = mysql::Query("SELECT id FROM `FriendsMsgsTemp` WHERE user_id = {} friend_id = {} res_size >= {}", user_id, friend_id, needed_size);
    //TODO FindFreeFriendMsgsTmp
}
}   // namespace model
}   // namespace chatroom