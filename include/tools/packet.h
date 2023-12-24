#pragma once
#include <span>
#include <vector>
#include <stdint.h>
#include <numeric>

namespace chatroom
{
struct PacketHeader
{
    uint16_t total_size;
    uint16_t msg_type;
};

static constexpr int kMaxTotalSize = 4096;

class RecvPacket
{
public:

    RecvPacket(const PacketHeader& network_header);

    auto& data_buf() noexcept { return data_buf_; }
    auto total_size() const noexcept { return header_.total_size; }
    auto data_size() const noexcept { return data_buf_.size(); }
    auto msg_type() const noexcept { return header_.msg_type; }

private:
    void set_total_size_safety(uint16_t total_size);
    void set_msg_type_safety(uint16_t msg_type);

    PacketHeader header_;
    std::vector<char> data_buf_;
};

class SendPacket
{
public:
    SendPacket(uint16_t msg_type, std::span<char> data);

    auto packed_buf() const noexcept { return packed_buf_; }

private:
    std::vector<char> packed_buf_;
};
}