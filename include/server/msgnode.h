#pragma once
#include <span>
#include <vector>
#include "basic.h"

namespace chatroom
{
struct Packet
{
    uint16_t total_size;
    uint16_t msg_type;
    char data[1];

    constexpr static int kHeaderSize = sizeof(total_size) + sizeof(msg_type);
};

class MsgNode
{
public:
    MsgNode(uint16_t data_size);
    ~MsgNode();

protected:
    uint16_t total_size_;
    Packet* packet_;
};

class RecvNode : public MsgNode
{
public:
    RecvNode(uint16_t data_size, uint16_t msg_type);

private:
    uint16_t msg_type_;
};

class SendNode : public MsgNode
{
public:
    SendNode(std::span<char> data, uint16_t msg_type);

private:
    uint16_t msg_type_;
};
}