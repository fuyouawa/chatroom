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
    static IOServicePool& instance();

    void Start();
    void Stop();

    IOService& NextIOService();

private:
    IOServicePool(size_t thread_size);

    std::vector<IOService> io_services_;
    std::vector<std::unique_ptr<IOService::work>> works_;
    std::vector<std::thread> threads_;
    size_t next_ioservice_index_;
};
}