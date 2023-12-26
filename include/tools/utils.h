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
    tmp.ParseFromArray(data.data(), data.size());
    return tmp;
}

inline std::vector<char> Serialize(const google::protobuf::Message& model) {
    std::vector<char> tmp(model.ByteSizeLong());
    model.SerializeToArray(tmp.data(), tmp.size());
    return tmp;
}
}