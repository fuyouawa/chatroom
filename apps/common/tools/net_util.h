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
        //TODO NetworkToHost
    }
    template<std::integral T>
    static T HostToNetwork(T net) {
        //TODO HostToNetwork
    }
};
}