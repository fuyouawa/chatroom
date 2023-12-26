#pragma once
#include <span>
#include <vector>
#include <stdint.h>
#include <numeric>
#include <google/protobuf/message.h>
#include <tools/utils.h>

namespace chatroom
{
struct PacketHeader
{
    uint16_t total_size;
    uint16_t msg_type;
};

struct Packet : public PacketHeader
{
    char data[1];
};

static constexpr int kMaxTotalSize = 4096;

class RecvPacket
{
public:
    RecvPacket(const PacketHeader& network_header);
    ~RecvPacket();

    auto total_size() const noexcept { return packet_->total_size; }
    auto data_size() const noexcept { return packet_->total_size - sizeof(PacketHeader); }
    auto data() const noexcept { return packet_->data; }
    auto data() noexcept { return packet_->data; }
    auto msg_type() const noexcept { return packet_->msg_type; }

    template<ConvertiableToMessage T>
    T DeserializeData() const {
        T tmp;
        tmp.ParseFromArray(data(), data_size());
        return tmp;
    }

private:
    void set_total_size_safety(uint16_t total_size);
    void set_msg_type_safety(uint16_t msg_type);

    Packet* packet_;
};

class SendPacket
{
public:
    SendPacket(uint16_t msg_type, std::vector<char>&& data) noexcept;
    SendPacket(uint16_t msg_type, const google::protobuf::Message& model);

    std::vector<char> Pack();

private:
    uint16_t msg_type_;
    std::vector<char> data_;
};
}