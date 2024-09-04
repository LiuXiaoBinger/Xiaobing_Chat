#include "AsioIOServicePool.h"

AsioIOServicePool::~AsioIOServicePool()
{
	void stop();
}

boost::asio::io_context& AsioIOServicePool::GetIOService()
{
	// TODO: �ڴ˴����� return ���
	auto& ioc = _ioServices[_nextIOService++];
	_nextIOService% _ioServices.size();
	return ioc;
}

void AsioIOServicePool::AsioIOServicePool::stop()
{
	//��Ϊ����ִ��work.reset��������iocontext��run��״̬���˳�
	//��iocontext�Ѿ����˶���д�ļ����¼��󣬻���Ҫ�ֶ�stop�÷���
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
	//����work
	for (int i = 0; i < size; ++i) {
		_works[i] = std::unique_ptr<Work>(new Work(_ioServices[i]));
	}
	for (int i = 0; i < size; ++i) {
		_thread.emplace_back([this ,i]() {
			_ioServices[i].run();
		});
	}

}