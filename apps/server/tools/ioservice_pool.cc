#include "tools/ioservice_pool.h"

namespace chatroom {
IOServicePool::IOServicePool()
    : io_services_(kThreadSize),
    next_ioservice_index_{0}
{
    for (size_t i = 0; i < kThreadSize; i++) {
        works_.push_back(std::make_unique<boost::asio::io_service::work>(io_services_[i]));
    }
    
    for (size_t i = 0; i < io_services_.size(); i++) {
        threads_.emplace_back([this, i](){ io_services_[i].run(); });
    }
}

IOServicePool::~IOServicePool() {
    Stop();
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

boost::asio::io_service& IOServicePool::NextIOService() {

	auto& service = io_services_[next_ioservice_index_++];
	if (next_ioservice_index_ == io_services_.size()) {
		next_ioservice_index_ = 0;
	}
	return service;
}
}   // namespace chatroom