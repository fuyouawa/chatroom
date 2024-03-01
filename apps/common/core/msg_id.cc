#include "common/core/msg_id.h"

namespace chatroom {
namespace msgid {
bool IsValid(uint16_t msgid) {
    return msgid::kMsgEndFlag > msgid;
}
bool IsAck(uint16_t msgid) {
    return msgid % 2 == 1;
}
uint16_t MapToAck(uint16_t msgid) {
    if (IsAck(msgid)) return msgid;
    return msgid + 1;
}
}   // namespace msgid
}   // namespace chatroom