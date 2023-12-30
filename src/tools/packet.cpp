#include "packet.h"
#include <cstring>
#include <arpa/inet.h>
#include <stdexcept>
#include <format>
#include "public.h"

namespace chatroom
{
RecvPacket::RecvPacket(const PacketHeader& network_header)
    : packet_{nullptr}
{
    set_total_size_safety(ntohs(network_header.total_size));
    set_msg_type_safety(ntohs(network_header.msg_type));
}

RecvPacket::~RecvPacket() {
    if (packet_)
        std::free(packet_);
}

void RecvPacket::set_total_size_safety(uint16_t total_size) {
    if (total_size > kMaxTotalSize)
        throw std::invalid_argument(std::format("The input 'total_size'({}) is greater than 'MaxTotalSize'({})!", total_size, kMaxTotalSize));
    else if (total_size < sizeof(PacketHeader))
        throw std::invalid_argument(std::format("The input 'total_size'({}) is less than 'HeaderSize'({})!", total_size, sizeof(PacketHeader)));
    packet_ = (Packet*)std::malloc(total_size);
    packet_->total_size = total_size;
}

void RecvPacket::set_msg_type_safety(uint16_t msg_type) {
    if (!CheckMsgTypeValid(msg_type))
        throw std::invalid_argument(std::format("The input 'msg_type'({}) is not valid!", msg_type));
    assert(packet_ != nullptr);
    packet_->msg_type = msg_type;
}

SendPacket::SendPacket(uint16_t msg_type, std::vector<char>&& data) noexcept
    : msg_type_{msg_type},
    data_{std::move(data)}
{
}

SendPacket::SendPacket(uint16_t msg_type, const google::protobuf::Message& model)
    : SendPacket{msg_type, Serialize(model)}
{
}


std::vector<char> SendPacket::Pack() {
    auto total_size = data_.size() + sizeof(PacketHeader);

    std::vector<char> buffer(total_size);

    auto packet = (Packet*)buffer.data();
    packet->total_size = htons(total_size);
    packet->msg_type = htons(msg_type_);

    std::memcpy(packet->data, data_.data(), data_.size());
    return buffer;
}
}