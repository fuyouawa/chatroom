#include "msgnode.h"
#include <memory>
#include <arpa/inet.h>

namespace chatroom
{
MsgNode::MsgNode(uint16_t data_size)
    : total_size_{data_size + Packet::kHeaderSize},
    packet_{(Packet*)malloc(total_size_)}
{
}

MsgNode::~MsgNode()
{
    free(packet_);
}

RecvNode::RecvNode(uint16_t data_size, uint16_t msg_type)
    : MsgNode{data_size},
    msg_type_{msg_type}
{
}

SendNode::SendNode(std::span<char> data, uint16_t msg_type)
    : MsgNode{data.size()},
    msg_type_{msg_type}
{
    packet_->total_size = htons(total_size_);
    packet_->msg_type = htons(msg_type_);
    std::copy(data.begin(), data.end(), packet_->data);
}
}