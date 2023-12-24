#include "packet.h"
#include <cstring>
#include <arpa/inet.h>
#include <stdexcept>
#include <format>
#include "public.h"

namespace chatroom
{
RecvPacket::RecvPacket(const PacketHeader& network_header) {
    set_total_size_safety(ntohs(network_header.total_size));
    set_msg_type_safety(ntohs(network_header.msg_type));
}

void RecvPacket::set_total_size_safety(uint16_t total_size) {
    if (total_size > kMaxTotalSize)
        throw std::invalid_argument(std::format("The input 'total_size'({}) is greater than 'MaxTotalSize'({})!", total_size, kMaxTotalSize));
    else if (total_size < sizeof(PacketHeader))
        throw std::invalid_argument(std::format("The input 'total_size'({}) is less than 'HeaderSize'({})!", total_size, sizeof(PacketHeader)));
    data_buf_.resize(total_size - sizeof(PacketHeader));
    header_.total_size = total_size;
}

void RecvPacket::set_msg_type_safety(uint16_t msg_type) {
    if (!CheckMsgTypeValid(msg_type))
        throw std::invalid_argument(std::format("The input 'msg_type'({}) is not valid!", msg_type));
    header_.msg_type = msg_type;
}

SendPacket::SendPacket(uint16_t msg_type, std::span<char> data) {
    auto total_size = data.size() + sizeof(PacketHeader);
    packed_buf_.resize(total_size);

    auto header = (PacketHeader*)packed_buf_.data();
    header->total_size = htons(total_size);
    header->msg_type = htons(msg_type);

    std::memcpy(header + 1, data.data(), data.size());
}
}