#pragma once
#include <span>
#include <vector>
#include <stdint.h>
#include <numeric>

namespace chatroom
{

class Packet
{
public:
    struct Header
    {
        uint16_t total_size;
        uint16_t msg_type;
    };
    static constexpr int kMaxTotalSize = 4096;

    Packet() = default;
    ~Packet() = default;

    void set_total_size_safety(uint16_t total_size);
    void set_msg_type_safety(uint16_t msg_type);

    auto total_size() const noexcept { return header_.total_size; }
    auto msg_type() const noexcept { return header_.msg_type; }
    auto data_size() const noexcept { return data_buf_.size(); }
    auto data() noexcept { return data_buf_.data(); }
    auto data() const noexcept { return data_buf_.data(); }

    void Clear();

protected:
    Header header_;
    std::vector<char> data_buf_;
};

class RecvPacket : public Packet
{
public:
    void FromNetworkHeader(const Header& header);
};

class SendPacket : public Packet
{
public:
    std::vector<char> NetworkPack();
};
}