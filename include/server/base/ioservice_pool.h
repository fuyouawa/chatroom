#pragma once
#include <utility>
#include <boost/asio.hpp>
#include <vector>
#include <thread>
#include "basic.h"

namespace chatroom
{
class IOServicePool : public Singleton<IOServicePool>
{
public:
    static IOServicePool& instance();

    void Start();
    void Stop();

    io_service& NextIOService();

private:
    IOServicePool(size_t thread_size);

    std::vector<io_service> io_services_;
    std::vector<std::unique_ptr<io_service::work>> works_;
    std::vector<std::thread> threads_;
    size_t next_ioservice_index_;
};
}