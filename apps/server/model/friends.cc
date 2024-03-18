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
const size_t FriendMsgsTmpCapacity = 256;

int FindFreeOrCreateFriendMsgsTmp(uint32_t user_id, uint32_t friend_id, size_t msg_size) {
    const auto needed_size = msg_size + 8;
    assert(needed_size <= FriendMsgsTmpCapacity);
    auto res = mysql::Query("SELECT id FROM `FriendsMsgsTemp` WHERE user_id = {} AND friend_id = {} AND res_size >= {}", user_id, friend_id, needed_size);
    if (res->next()) {
        return res->getUInt(1);
    }
    else {
        datapb::FriendMsgsTemp tmp{};
        auto suc = mysql::Update("INSERT INTO `FriendsMsgsTemp` (user_id, friend_id, msgs, res_size) VALUES ({}, {}, '{}', {})",
                                user_id,
                                friend_id,
                                tmp.SerializeAsString(),
                                FriendMsgsTmpCapacity - tmp.ByteSizeLong());
        assert(suc);
        return mysql::GetLastInsertId();
    }
}
}   // namespace


void SaveFriendMsgToTmp(uint32_t user_id, uint32_t friend_id, std::string_view msg) {
    std::string trans_msg;
    for (auto &ch : msg) {
        if (ch == '\'')
            trans_msg += "\\'";
        else
            trans_msg += ch;
    }
    
    auto stor_id = FindFreeOrCreateFriendMsgsTmp(user_id, friend_id, trans_msg.size());
    auto res = mysql::Query("SELECT msgs, res_size, msg_count FROM `FriendsMsgsTemp` WHERE id = {}", stor_id);
    res->next();
    auto msgs_str = res->getString(1);
    auto res_size = res->getUInt(2);
    auto msg_count = res->getUInt(3);

    datapb::FriendMsgsTemp msgs_tmp;
    msgs_tmp.ParseFromString(msgs_str.asStdString());
    assert(static_cast<uint>(msgs_tmp.msgs_size()) == msg_count);
    assert(FriendMsgsTmpCapacity - res_size == msgs_tmp.ByteSizeLong());
    msgs_tmp.add_msgs(trans_msg.data());
    assert(msgs_tmp.SerializeAsString().size() == msgs_tmp.ByteSizeLong());
    mysql::Update("UPDATE `FriendsMsgsTemp` SET `msgs`='{}', res_size={}, msg_count={} WHERE `id`={}",
                msgs_tmp.SerializeAsString(),
                FriendMsgsTmpCapacity - msgs_tmp.ByteSizeLong(),
                msg_count + 1,
                stor_id);
}


void ClearFriendMsgsFromTmp(uint32_t user_id, uint32_t friend_id) {
    auto suc = mysql::Update("DELETE FROM `FriendsMsgsTemp` WHERE user_id = {} AND friend_id = {}", user_id, friend_id);
    assert(suc);
}

std::vector<std::string> GetFriendMsgsFromTmp(uint32_t user_id, uint32_t friend_id) {
    auto res = mysql::Query("SELECT msgs, res_size, msg_count FROM `FriendsMsgsTemp` WHERE user_id = {} AND friend_id = {}", friend_id, user_id);
    std::vector<std::string> total;
    while (res->next()) {
        auto msgs_str = res->getString(1);
        auto res_size = res->getUInt(2);
        auto msg_count = res->getUInt(3);

        datapb::FriendMsgsTemp msgs_tmp;
        msgs_tmp.ParseFromString(msgs_str.asStdString());
        assert(msgs_tmp.ByteSizeLong() == FriendMsgsTmpCapacity - res_size);
        assert(static_cast<uint>(msgs_tmp.msgs_size()) == msg_count);
        if (msgs_tmp.msgs_size() == 0) continue;
        for (auto &msg : *msgs_tmp.mutable_msgs()) {
            total.push_back(std::move(msg));
        }
    }
    return total;
}
}   // namespace model
}   // namespace chatroom