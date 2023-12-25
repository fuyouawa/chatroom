#pragma once
namespace chatroom
{
enum MsgType {
    kLoginMsg
};

constexpr int kPort = 8888;
constexpr const char* kServerIp = "127.0.0.1";

inline bool CheckMsgTypeValid(short msg_type) { return msg_type <= kLoginMsg; }
}