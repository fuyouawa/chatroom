#pragma once
namespace chatroom
{
enum MsgType {
    kRegisterMsg,
    kRegisterMsgAck,
    kLoginMsg,
    kLoginMsgAck,
    kEmergencyMsg
};

enum EmergencyEvent {
    kForceOfflineEvent
};

inline bool CheckMsgTypeValid(short msg_type) { return msg_type <= kEmergencyMsg; }
}