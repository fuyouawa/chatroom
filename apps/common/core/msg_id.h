#pragma once
#include <stdint.h>

namespace chatroom {
namespace msgid {
enum ID {
    kMsgRegister,
    kMsgRegisterAck,
    kMsgLogin,
    kMsgLoginAck,
    kMsgAddFriend,
    kMsgAddFriendAck,
    kMsgRemoveFriend,
    kMsgRemoveFriendAck,
    kMsgGetFriends,
    kMsgGetFriendsAck,
    kMsgCreateGroup,
    kMsgCreateGroupAck,
    kMsgGetJoinedGroups,
    kMsgGetJoinedGroupsAck,
    kMsgJoinGroup,
    kMsgJoinGroupAck,
    kMsgQuitGroup,
    kMsgQuitGroupAck,
    kMsgEndFlag
};
bool IsValid(uint16_t msgid);
bool IsAck(uint16_t msgid);
uint16_t MapToAck(uint16_t msgid);
}   // namespace msgid
}   // namespace chatroom