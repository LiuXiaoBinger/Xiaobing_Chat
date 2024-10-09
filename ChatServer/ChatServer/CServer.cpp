#include "CServer.h"
#include <iostream>
#include "AsioIOServicePool.h"
#include "UserMgr.h"
CServer::CServer(boost::asio::io_context& ioc, short prot):
	_io_context(ioc),_prot(prot),_acceptor(ioc,tcp::endpoint(tcp::v4(),prot)
)
{
	std::cout << "Server start success, listen on port : " << prot << std::endl;
	
	startAccept();
}

CServer::~CServer()
{

}

void CServer::clearCSessionData(std::string session_id) {
	

	if (_sessions.find(session_id) != _sessions.end()) {
		//移除用户和session的关联
		UserMgr::GetInstance()->RmvUserSession(_sessions[session_id]->GetUserId());
	}
	{
		lock_guard<mutex> lock(_mutex);
		_sessions.erase(session_id);
	}
}

void CServer::HandleAccept(std::shared_ptr<CSession> newCSession,  const boost::system::error_code& ec)
{
	if (!ec) {
		newCSession->Start();
		std::lock_guard<std::mutex> lock(_mutex);
		_sessions.insert(std::make_pair(newCSession->GetSessionId(), newCSession));
		std::cout << "Server start success, Accept " << std::endl;
	}
	startAccept();
}
//StartAccept函数中虽然new_session是一个局部变量，但是我们通过bind操作，将new_session作为数值传递给bind函数
//，而bind函数返回的函数对象内部引用了该new_session所以引用计数增加1，这样保证了new_session不会被释放。 
//在HandleAccept函数里调用session的start函数监听对端收发数据，并将session放入map中，保证session不被自动释放。
//此外，需要封装一个释放函数，将session从map中移除，当其引用计数为0则自动释放
void CServer::startAccept()
{
	auto& ioc = AsioIOServicePool::GetInstance()->GetIOService();
	std::shared_ptr<CSession> new_session = std::make_shared<CSession>(ioc, this);
	_acceptor.async_accept(new_session->getSocket(), 
		std::bind(&CServer::HandleAccept, this, new_session, std::placeholders::_1));
	
}
