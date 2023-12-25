#pragma once
#include <google/protobuf/message.h>
#include <type_traits>

namespace chatroom
{
template<typename T>
concept ConvertiableToMessage = std::is_convertible_v<T*, google::protobuf::Message*>;

template<ConvertiableToMessage T>
T Deserialize(const std::vector<char>& data) {
    T tmp;
    tmp.ParseFromArray(data.data(), data.size()); // SerializeToArray()
    return tmp;
}

inline std::vector<char> Serialize(const google::protobuf::Message& data) {
    std::vector<char> tmp(data.ByteSizeLong());
    data.SerializeToArray(tmp.data(), tmp.size());
    return tmp;
}
}