#include "ioservice_pool.h"

namespace cluster_chat_room
{
IOServicePool::IOServicePool()
    : io_services_(kThreadSize),
    works_(kThreadSize),
    next_ioservice_index_{0}
{
}

void IOServicePool::Start()
{
    for (size_t i = 0; i < works_.size(); i++) {
        works_[i] = std::make_unique<io_service::work>(io_services_[i]);
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

io_service& IOServicePool::NextIOService() {

	auto& service = io_services_[next_ioservice_index_++];
	if (next_ioservice_index_ == io_services_.size()) {
		next_ioservice_index_ = 0;
	}
	return service;
}
}