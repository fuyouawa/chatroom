#include "net_util.h"
#include <boost/asio/detail/socket_ops.hpp>

namespace chatroom {
namespace socket {
short ntohs(short val) {
    return boost::asio::detail::socket_ops::network_to_host_short(val);
}
short htons(short val) {
    return boost::asio::detail::socket_ops::host_to_network_short(val);
}
}
}