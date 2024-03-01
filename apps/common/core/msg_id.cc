#include "msg_id.h"

namespace chatroom {
namespace msgid {
bool IsValid(uint16_t msgid) noexcept {
    return msgid::kMsgEndFlag > msgid;
}
bool IsAck(uint16_t msgid) noexcept {
    return msgid % 2 == 1;
}
uint16_t MapToAck(uint16_t msgid) noexcept {
    if (IsAck(msgid)) return msgid;
    return msgid + 1;
}
}   // namespace msgid
}   // namespace chatroom