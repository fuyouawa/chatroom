#include "protobuf_utils.h"

namespace chatroom
{
std::vector<char> Serialize(const google::protobuf::Message& model) {
    std::vector<char> tmp(model.ByteSizeLong());
    model.SerializeToArray(tmp.data(), tmp.size());
    return tmp;
}
}