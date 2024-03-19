#include "model/friends.h"
#include "tools/mysql.h"
#include "common/datapb/friend_msgs_temp.pb.h"
#include <ranges>
#include <cassert>

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

namespace {
const size_t kFriendMsgsCapacity = 256;

int FindFreeOrCreateFriendMessage(uint32_t user_id, uint32_t friend_id, size_t msg_size) {
    const auto needed_size = msg_size + 8;
    assert(needed_size <= kFriendMsgsCapacity);
    auto res = mysql::Query("SELECT id FROM `FriendMessages` WHERE user_id = {} AND friend_id = {} AND res_size >= {}", user_id, friend_id, needed_size);
    if (res->next()) {
        return res->getUInt(1);
    }
    else {
        datapb::FriendMsgsTemp tmp{};
        auto suc = mysql::Update("INSERT INTO `FriendMessages` (user_id, friend_id, msgs, res_size) VALUES ({}, {}, '{}', {})",
                                user_id,
                                friend_id,
                                tmp.SerializeAsString(),
                                kFriendMsgsCapacity - tmp.ByteSizeLong());
        assert(suc);
        return mysql::GetLastInsertId();
    }
}
}   // namespace


void SaveFriendMessage(uint32_t user_id, uint32_t friend_id, std::string_view msg) {
    std::string trans_msg;
    for (auto &ch : msg) {
        if (ch == '\'')
            trans_msg += "\\'";
        else
            trans_msg += ch;
    }
    
    auto stor_id = FindFreeOrCreateFriendMessage(user_id, friend_id, trans_msg.size());
    auto res = mysql::Query("SELECT msgs, res_size FROM `FriendMessages` WHERE id = {}", stor_id);
    res->next();
    auto msgs_str = res->getString(1);
    auto res_size = res->getUInt(2);

    datapb::FriendMsgsTemp msgs_tmp;
    msgs_tmp.ParseFromString(msgs_str.asStdString());
    assert(kFriendMsgsCapacity - res_size == msgs_tmp.ByteSizeLong());
    msgs_tmp.add_msgs(trans_msg.data());
    assert(msgs_tmp.SerializeAsString().size() == msgs_tmp.ByteSizeLong());
    mysql::Update("UPDATE `FriendMessages` SET `msgs`='{}', res_size={} WHERE `id`={}",
                msgs_tmp.SerializeAsString(),
                kFriendMsgsCapacity - msgs_tmp.ByteSizeLong(),
                stor_id);
}

google::protobuf::RepeatedPtrField<std::string> GetFriendMessages(uint32_t user_id, uint32_t friend_id) {
    auto res = mysql::Query("SELECT msgs, res_size FROM `FriendMessages` WHERE user_id = {} AND friend_id = {}", friend_id, user_id);
    google::protobuf::RepeatedPtrField<std::string> total;
    datapb::FriendMsgsTemp msgs_tmp;
    while (res->next()) {
        auto msgs_str = res->getString(1);
        auto res_size = res->getUInt(2);

        msgs_tmp.ParseFromString(msgs_str.asStdString());
        assert(msgs_tmp.ByteSizeLong() == kFriendMsgsCapacity - res_size);
        if (msgs_tmp.msgs_size() == 0) continue;
        total.MergeFrom(msgs_tmp.msgs());
    }
    return total;
}
}   // namespace model
}   // namespace chatroom