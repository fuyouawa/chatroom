#pragma once
#include <stdint.h>

namespace chatroom {
namespace msgid {
enum ID {
    kMsgUserRegister,
    kMsgUserRegisterAck,
    kMsgUserLogin,
    kMsgUserLoginAck,
    kMsgUserAddFriend,
    kMsgUserAddFriendAck,
    kMsgUserRemoveFriend,
    kMsgUserRemoveFriendAck,
    kMsgUserGetFriends,
    kMsgUserGetFriendsAck,
    kMsgEndFlag
};
bool IsValid(uint16_t msgid) noexcept;
bool IsAck(uint16_t msgid) noexcept;
uint16_t MapToAck(uint16_t msgid) noexcept;
}   // namespace msgid
}   // namespace chatroom