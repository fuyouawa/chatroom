#pragma once
#include <stdint.h>

namespace chatroom {
enum class MessageID: uint16_t {
    kUserRegister,
    kUserRegisterAck,
    kUserLogin,
    kUserLoginAck,
    kUserForceOffline,
};
}