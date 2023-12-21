#include <boost/asio.hpp>
#include <vector>
#include <thread>
#include "basic.hpp"

namespace cluster_chat_room
{
class IOServicePool : public Singleton<IOServicePool>
{
public:
    static inline const int kThreadSize = std::thread::hardware_concurrency();

    void Start();
    void Stop();

    io_service& NextIOService();

private:
    IOServicePool();

    std::vector<io_service> io_services_;
    std::vector<std::unique_ptr<io_service::work>> works_;
    std::vector<std::thread> threads_;
    size_t next_ioservice_index_;
};
}