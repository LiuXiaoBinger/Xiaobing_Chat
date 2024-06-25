#include "AsioIOServicePool.h"
#include <iostream>
using namespace std;
AsioIOServicePool::AsioIOServicePool(std::size_t size) :_ioServices(size),
_works(size), _nextIOService(0) {
	//这里将_ioServices里面的上下文都注册work，防止上下文调度run函数直接退出不论训事件 work类似于监工
	for (std::size_t i = 0; i < size; ++i) {
		_works[i] = std::unique_ptr<Work>(new Work(_ioServices[i]));
	}

	//遍历多个ioservice，创建多个线程，每个线程内部启动ioservice
	for (std::size_t i = 0; i < _ioServices.size(); ++i) {
		_threads.emplace_back([this, i]() {
			std::cout << "多线程         "  << std::this_thread::get_id() << std::endl;
			_ioServices[i].run();
			});
	}
}

AsioIOServicePool::~AsioIOServicePool() {
	Stop();
	std::cout << "AsioIOServicePool destruct" << endl;
}

boost::asio::io_context& AsioIOServicePool::GetIOService() {
	auto& service = _ioServices[_nextIOService++];
	/*if (_nextIOService == _ioServices.size()) {
		_nextIOService = 0;
	}*/
	_nextIOService = _nextIOService % _ioServices.size();
	return service;
}

void AsioIOServicePool::Stop() {
	//因为仅仅执行work.reset并不能让iocontext从run的状态中退出
	//当iocontext已经绑定了读或写的监听事件后，还需要手动stop该服务。
	for (auto& work : _works) {
		//把服务先停止
		work->get_io_context().stop();
		work.reset();
	}
	//回收对象之前需要回收一下线程防止析构完有些线程没有退出，程序卡死
	for (auto& t : _threads) {
		t.join();
	}
}
