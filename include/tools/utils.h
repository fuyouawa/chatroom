#include <google/protobuf/message.h>

namespace chatroom
{
template<typename T>
T Deserialize(const std::vector<char>& data) {
    T tmp;
    tmp.ParseFromArray(data.data(), data.size());
    return tmp;
}
}