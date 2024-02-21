#include <stdint.h>
#include <concepts>
#include <boost/asio/detail/socket_ops.hpp>

namespace chatroom
{
class NetUtil
{
public:
    template<std::integral T>
    static T NetworkToHost(T net) {
        if constexpr (std::is_same_v<std::make_unsigned_t<T>, uint16_t>) {
            return boost::asio::detail::socket_ops::network_to_host_short(net);
        }
        else if constexpr (std::is_same_v<std::make_unsigned_t<T>, uint32_t>) {
            return boost::asio::detail::socket_ops::network_to_host_long(net);
        }
        else {
            static_assert(sizeof(T) == 0, "T is not supported");
            return 0;
        }
    }
    template<std::integral T>
    static T HostToNetwork(T host) {
        if constexpr (std::is_same_v<std::make_unsigned_t<T>, uint16_t>) {
            return boost::asio::detail::socket_ops::host_to_network_short(host);
        }
        else if constexpr (std::is_same_v<std::make_unsigned_t<T>, uint32_t>) {
            return boost::asio::detail::socket_ops::host_to_network_long(host);
        }
        else {
            static_assert(sizeof(T) == 0, "T is not supported");
            return 0;
        }
    }
};
}