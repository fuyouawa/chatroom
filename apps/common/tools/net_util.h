#include <stdint.h>
#include <concepts>
#ifdef _WIN32
#include <WinSock2.h>
#else
#include <arpa/inet.h>
#endif

namespace chatroom
{
class NetUtil
{
public:
    template<std::integral T>
    static T NetworkToHost(T net) {
        if constexpr (std::is_same_v<std::make_unsigned_t<T>, uint16_t>) {
            return ntohs(net);
        }
        else if constexpr (std::is_same_v<std::make_unsigned_t<T>, uint32_t>) {
            return ntohl(net);
        }
        else {
            static_assert(sizeof(T) == 0, "T is not supported");
            return 0;
        }
    }
    template<std::integral T>
    static T HostToNetwork(T net) {
        if constexpr (std::is_same_v<std::make_unsigned_t<T>, uint16_t>) {
            return ntohs(net);
        }
        else if constexpr (std::is_same_v<std::make_unsigned_t<T>, uint32_t>) {
            return ntohl(net);
        }
        else {
            static_assert(sizeof(T) == 0, "T is not supported");
            return 0;
        }
    }
};
}