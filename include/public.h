#pragma once
namespace chatroom
{
enum MsgType {
    kRegisterMsg,
    kRegisterMsgAck,
    kLoginMsg,
};

inline bool CheckMsgTypeValid(short msg_type) { return msg_type <= kLoginMsg; }
}