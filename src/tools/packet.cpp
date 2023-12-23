#include "packet.h"
#include <memory>
#include <arpa/inet.h>
#include <stdexcept>
#include <format>
#include "public.h"

namespace chatroom
{
void Packet::set_total_size_safety(uint16_t total_size) {
    if (total_size > kMaxTotalSize)
        throw std::invalid_argument(std::format("The input 'total_size'({}) is greater than 'MaxTotalSize'({})!", total_size, kMaxTotalSize));
    else if (total_size < sizeof(Header))
        throw std::invalid_argument(std::format("The input 'total_size'({}) is less than 'HeaderSize'({})!", total_size, sizeof(Header)));
    data_buf_.resize(total_size - sizeof(Header));
    header_.total_size = total_size;
}

void Packet::set_msg_type_safety(uint16_t msg_type) {
    if (!CheckMsgTypeValid(msg_type))
        throw std::invalid_argument(std::format("The input 'msg_type'({}) is not valid!", msg_type));
    header_.msg_type = msg_type;
}

void Packet::Clear() {
    data_buf_.clear();
}

void RecvPacket::FromNetworkHeader(const Header& header) {
    set_total_size_safety(ntohs(header.total_size));
    set_msg_type_safety(ntohs(header.msg_type));
}

std::vector<char> SendPacket::NetworkPack() {
    std::vector<char> total_buf(total_size());

    auto header = (Header*)total_buf.data();
    header->total_size = ntohs(total_size());;
    header->msg_type = ntohs(msg_type());

    if (data_buf_.size() > 0)
        std::copy(total_buf.begin() + sizeof(Header), data_buf_.begin(), data_buf_.end());
    return total_buf;
}
}