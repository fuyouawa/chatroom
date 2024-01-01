#include "packet.h"
#include <cstring>
#include <arpa/inet.h>
#include <stdexcept>
#include <format>

namespace chatroom
{
RecvPacket::RecvPacket(const PacketHeader& network_header)
    : packet_{nullptr}
{
    set_total_size_safety(ntohs(network_header.total_size));
    set_msgid_safety(ntohs(network_header.msgid));
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

void RecvPacket::set_msgid_safety(uint16_t msgid) {
    assert(packet_ != nullptr);
    packet_->msgid = msgid;
}

SendPacket::SendPacket(MessageID msgid, const google::protobuf::Message& model)
    : msgid_{msgid},
    data_(model.ByteSizeLong())
{
    model.SerializeToArray(data_.data(), data_.size());
}

std::vector<char> SendPacket::Pack() {
    auto total_size = data_.size() + sizeof(PacketHeader);

    std::vector<char> buffer(total_size);

    auto packet = (Packet*)buffer.data();
    packet->total_size = htons(total_size);
    packet->msgid = htons(static_cast<uint16_t>(msgid_));

    std::memcpy(packet->data, data_.data(), data_.size());
    return buffer;
}
}