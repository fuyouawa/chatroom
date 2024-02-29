#pragma once
#include <span>
#include <vector>
#include <stdint.h>
#include <numeric>
#include <google/protobuf/message.h>
#include "common/core/msg_id.h"

namespace chatroom {
struct PacketHeader {
    uint16_t total_size;
    uint16_t msgid;
};

template<typename T>
concept ConvertiableToMessage = std::is_convertible_v<T*, google::protobuf::Message*>;

struct Packet : public PacketHeader {
    char data[1];
};

class RecvPacket {
public:
    RecvPacket(const PacketHeader& network_header);
    ~RecvPacket();

    RecvPacket(const RecvPacket&) = delete;
    RecvPacket(RecvPacket&& right);

    auto total_size() const noexcept { return packet_->total_size; }
    auto data_size() const noexcept { return packet_->total_size - sizeof(PacketHeader); }
    auto data() const noexcept { return packet_->data; }
    auto data() noexcept { return packet_->data; }
    auto msgid() const noexcept { return static_cast<MessageID>(packet_->msgid); }

    template<ConvertiableToMessage T>
    T DeserializeData() const {
        T tmp;
        tmp.ParseFromArray(data(), data_size());
        return tmp;
    }

private:
    void set_total_size_safety(uint16_t total_size);
    void set_msgid_safety(uint16_t msgid);

    Packet* packet_;
};

class SendPacket {
public:
    SendPacket(MessageID msgid, std::vector<char>&& data) noexcept;
    SendPacket(MessageID msgid, const google::protobuf::Message& model);

    std::vector<char> Pack() const;

private:
    MessageID msgid_;
    std::vector<char> data_;
};
}   // namespace chatroom