#pragma once
#include <span>
#include <vector>
#include <stdint.h>
#include <numeric>

namespace chatroom
{
class PacketHeader
{
public:
    static constexpr int kMaxTotalSize = 4096;
    static constexpr int kHeaderSize = 4;

    PacketHeader() = default;
    ~PacketHeader() = default;

    void set_total_size_safety(uint16_t total_size);
    void set_msg_type_safety(uint16_t msg_type);

    uint16_t total_size() const noexcept { return total_size_; }
    uint16_t msg_type() const noexcept { return msg_type_; }
    uint16_t data_size() const noexcept { return total_size_ - kHeaderSize; }

protected:
    uint16_t total_size_;
    uint16_t msg_type_;
};

class RecvPacket : public PacketHeader
{
public:
    void Clear();

    char* data();

protected:
    std::vector<char> data_buf_;
};

class SendPacket : public RecvPacket
{
public:
    std::vector<char> PackToNetworkPacket();
};
}