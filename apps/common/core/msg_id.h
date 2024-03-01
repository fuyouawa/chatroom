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
    kMsgEndFlag
};
bool IsValid(uint16_t msgid) noexcept;
bool IsAck(uint16_t msgid) noexcept;
uint16_t MapToAck(uint16_t msgid) noexcept;
}   // namespace msgid
}   // namespace chatroom