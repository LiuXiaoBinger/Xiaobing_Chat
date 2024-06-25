#include "AsioIOServicePool.h"
#include <iostream>
using namespace std;
AsioIOServicePool::AsioIOServicePool(std::size_t size) :_ioServices(size),
_works(size), _nextIOService(0) {
	//���ｫ_ioServices����������Ķ�ע��work����ֹ�����ĵ���run����ֱ���˳�����ѵ�¼� work�����ڼ๤
	for (std::size_t i = 0; i < size; ++i) {
		_works[i] = std::unique_ptr<Work>(new Work(_ioServices[i]));
	}

	//�������ioservice����������̣߳�ÿ���߳��ڲ�����ioservice
	for (std::size_t i = 0; i < _ioServices.size(); ++i) {
		_threads.emplace_back([this, i]() {
			std::cout << "���߳�         "  << std::this_thread::get_id() << std::endl;
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
	//��Ϊ����ִ��work.reset��������iocontext��run��״̬���˳�
	//��iocontext�Ѿ����˶���д�ļ����¼��󣬻���Ҫ�ֶ�stop�÷���
	for (auto& work : _works) {
		//�ѷ�����ֹͣ
		work->get_io_context().stop();
		work.reset();
	}
	//���ն���֮ǰ��Ҫ����һ���̷߳�ֹ��������Щ�߳�û���˳���������
	for (auto& t : _threads) {
		t.join();
	}
}