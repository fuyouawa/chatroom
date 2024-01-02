#pragma once
#include <utility>
#include <boost/asio.hpp>
#include <vector>
#include <thread>
#include "basic/singleton.h"
#include "basic/usings.h"

namespace chatroom
{
class IOServicePool : public Singleton<IOServicePool>
{
public:
    static inline const size_t kThreadSize = std::thread::hardware_concurrency();
    ~IOServicePool();

    IOService& NextIOService();

private:
    friend Singleton<IOServicePool>;
    IOServicePool();

    void Stop();

    std::vector<IOService> io_services_;
    std::vector<std::unique_ptr<IOService::work>> works_;
    std::vector<std::thread> threads_;
    size_t next_ioservice_index_;
};
}