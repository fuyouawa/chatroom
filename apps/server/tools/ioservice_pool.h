#pragma once
#include <utility>
#include <boost/asio.hpp>
#include <vector>
#include <thread>
#include "common/core/singleton.h"

namespace chatroom {
class IOServicePool : public Singleton<IOServicePool> {
public:
    static inline const size_t kThreadSize = std::thread::hardware_concurrency();
    ~IOServicePool();

    boost::asio::io_service& NextIOService();

private:
    friend Singleton<IOServicePool>;
    IOServicePool();

    void Stop();

    std::vector<boost::asio::io_service> io_services_;
    std::vector<std::unique_ptr<boost::asio::io_service::work>> works_;
    std::vector<std::thread> threads_;
    size_t next_ioservice_index_;
};
}   // namespace chatroom