#include "common/core/packet.h"
#include <cstring>
#include <stdexcept>
#include <format>
#include "common/core/msg_id.h"

#include <common/tools/net_util.h>

namespace chatroom {
namespace {
constexpr size_t kMaxTotalSize = 4096;
}   // namespace

void CheckTotalSize(size_t total_size) {
    if (total_size > kMaxTotalSize)
        throw std::invalid_argument(std::format("The input 'total_size'({}) is greater than 'MaxTotalSize'({})!", total_size, kMaxTotalSize));
    else if (total_size < sizeof(PacketHeader))
        throw std::invalid_argument(std::format("The input 'total_size'({}) is less than 'HeaderSize'({})!", total_size, sizeof(PacketHeader)));
}

void CheckMsgID(uint16_t msgid) {
    if (!msgid::IsValid(msgid))
        throw std::invalid_argument("Invalid message id!");
}

RecvPacket::RecvPacket(const PacketHeader& network_header)
    : packet_{nullptr}
{
    set_total_size_safety(socket::ntohs(network_header.total_size));
    set_msgid_safety(socket::ntohs(network_header.msgid));
}

RecvPacket::RecvPacket(RecvPacket&& right) {
    packet_ = right.packet_;
    right.packet_ = nullptr;
}

RecvPacket::~RecvPacket() {
    if (packet_)
        std::free(packet_);
}

void RecvPacket::set_total_size_safety(uint16_t total_size) {
    CheckTotalSize(total_size);
    packet_ = (Packet*)std::malloc(total_size);
    packet_->total_size = total_size;
}

void RecvPacket::set_msgid_safety(uint16_t msgid) {
    CheckMsgID(msgid);
    assert(packet_ != nullptr);
    packet_->msgid = msgid;
}

SendPacket::SendPacket(uint16_t msgid, const google::protobuf::Message& model)
    : msgid_{msgid},
    data_(model.ByteSizeLong())
{
    CheckTotalSize(data_.size() + sizeof(PacketHeader));
    CheckMsgID(msgid_);
    model.SerializeToArray(data_.data(), data_.size());
}

std::vector<char> SendPacket::Pack() const {
    const auto total_size = data_.size() + sizeof(PacketHeader);

    std::vector<char> buffer(total_size);

    const auto packet = (Packet*)buffer.data();
    packet->total_size = socket::htons(static_cast<uint16_t>(total_size));
    packet->msgid = socket::htons(msgid_);

    std::memcpy(packet->data, data_.data(), data_.size());
    return buffer;
}
}   // namespace chatroom