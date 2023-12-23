#include "packet.h"
#include <memory>
#include <arpa/inet.h>
#include <stdexcept>
#include <format>
#include "public.h"

namespace chatroom
{
void PacketHeader::set_total_size_safety(uint16_t total_size) {
    if (total_size > kMaxTotalSize)
        throw std::invalid_argument(std::format("The input 'total_size'({}) is greater than 'MaxTotalSize'({})!", total_size, kMaxTotalSize));
    else if (total_size < kHeaderSize)
        throw std::invalid_argument(std::format("The input 'total_size'({}) is less than 'HeaderSize'({})!", total_size, kHeaderSize));
    total_size_ = total_size;
}

void PacketHeader::set_msg_type_safety(uint16_t msg_type) {
    if (!CheckMsgTypeValid(msg_type))
        throw std::invalid_argument(std::format("The input 'msg_type'({}) is not valid!", msg_type));
    msg_type_ = msg_type;
}

void RecvPacket::Clear() {
    data_buf_.clear();
}

char* RecvPacket::data() {
    if (data_buf_.size() != data_size()) {
        data_buf_.clear();
        data_buf_.resize(data_size());
    }
    return data_buf_.data();
}

std::vector<char> SendPacket::PackToNetworkPacket() {
    std::vector<char> total_buf(total_size_);

    auto header_buf = (uint16_t*)total_buf.data();
    *header_buf = ntohs(total_size_); ++header_buf;
    *header_buf = ntohs(msg_type_);

    if (data_buf_.size() > 0)
        std::copy(total_buf.begin() + kHeaderSize, data_buf_.begin(), data_buf_.end());
    return total_buf;
}
}