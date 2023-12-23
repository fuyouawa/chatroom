#include "ioservice_pool.h"

namespace chatroom
{
IOServicePool::IOServicePool(size_t thread_size)
    : io_services_(thread_size),
    works_(thread_size),
    next_ioservice_index_{0}
{
}

IOServicePool& IOServicePool::instance() {
    static IOServicePool pool{std::thread::hardware_concurrency()};
    return pool;
}

void IOServicePool::Start()
{
    for (size_t i = 0; i < works_.size(); i++) {
        works_[i] = std::make_unique<IOService::work>(io_services_[i]);
    }
    
    for (size_t i = 0; i < io_services_.size(); i++) {
        threads_.emplace_back([this, i](){ io_services_[i].run(); });
    }
}

void IOServicePool::Stop()
{
    for (auto& work : works_) {
        work.reset();
    }

    for (auto& t : threads_) {
        t.join();
    }
}

IOService& IOServicePool::NextIOService() {

	auto& service = io_services_[next_ioservice_index_++];
	if (next_ioservice_index_ == io_services_.size()) {
		next_ioservice_index_ = 0;
	}
	return service;
}
}