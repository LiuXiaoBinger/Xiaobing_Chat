#include "AsioIOServicePool.h"

AsioIOServicePool::~AsioIOServicePool()
{
	void stop();
}

boost::asio::io_context& AsioIOServicePool::GetIOService()
{
	// TODO: 在此处插入 return 语句
	auto& ioc = _ioServices[_nextIOService++];
	_nextIOService% _ioServices.size();
	return ioc;
}

void AsioIOServicePool::AsioIOServicePool::stop()
{
	//因为仅仅执行work.reset并不能让iocontext从run的状态中退出
	//当iocontext已经绑定了读或写的监听事件后，还需要手动stop该服务。
	for (auto& work : _works) {
		work->get_io_context().stop();
		work.reset();
	}
	for (auto& m_thread : _thread)
	{
		m_thread.join();
	}
}

AsioIOServicePool::AsioIOServicePool(std::size_t size):_ioServices(size),
_works(size), _nextIOService(0) {
	//创建work
	for (int i = 0; i < size; ++i) {
		_works[i] = std::unique_ptr<Work>(new Work(_ioServices[i]));
	}
	for (int i = 0; i < size; ++i) {
		_thread.emplace_back([this ,i]() {
			_ioServices[i].run();
		});
	}

}