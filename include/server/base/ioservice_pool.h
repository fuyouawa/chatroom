#pragma once
#include <utility>
#include <boost/asio.hpp>
#include <vector>
#include <thread>
#include "basic.h"
#include "usings.h"

namespace chatroom
{
class IOServicePool : public Singleton<IOServicePool>
{
public:
    static inline const size_t kThreadSize = std::thread::hardware_concurrency();

    void Start();
    void Stop();

    IOService& NextIOService();

private:
    std::vector<std::unique_ptr<IOService>> io_services_;
    std::vector<std::unique_ptr<IOService::work>> works_;
    std::vector<std::thread> threads_;
    size_t next_ioservice_index_;
};
}