#include "msg_id.h"

namespace chatroom {
bool IsValidMsgID(MessageID msgid) noexcept {
    constexpr auto kMaxMsgID = static_cast<uint16_t>(MessageID::kUserRemoveFriendAck);
    return static_cast<uint16_t>(msgid) <= kMaxMsgID;
}

bool IsMsgAckID(MessageID msgid) noexcept {
    return static_cast<uint16_t>(msgid) % 2 == 1;
}

MessageID MapToMsgAckID(MessageID msgid) noexcept {
    if (IsMsgAckID(msgid)) return msgid;
    return static_cast<MessageID>(static_cast<uint16_t>(msgid) + 1);
}
}