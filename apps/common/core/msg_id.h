#pragma once
#include <stdint.h>

namespace chatroom {
enum class MessageID: uint16_t {
    kUserRegister,
    kUserRegisterAck,
    kUserLogin,
    kUserLoginAck,
    kUserAddFriend,
    kUserAddFriendAck,
    kUserRemoveFriend,
    kUserRemoveFriendAck,
};

bool IsValidMsgID(MessageID msgid) noexcept;
bool IsMsgAckID(MessageID msgid) noexcept;
MessageID MapToMsgAckID(MessageID msgid) noexcept;
}   // namespace chatroom