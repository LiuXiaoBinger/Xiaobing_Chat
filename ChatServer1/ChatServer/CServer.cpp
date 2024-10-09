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
		//�Ƴ��û���session�Ĺ���
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
//StartAccept��������Ȼnew_session��һ���ֲ���������������ͨ��bind��������new_session��Ϊ��ֵ���ݸ�bind����
//����bind�������صĺ��������ڲ������˸�new_session�������ü�������1��������֤��new_session���ᱻ�ͷš� 
//��HandleAccept���������session��start���������Զ��շ����ݣ�����session����map�У���֤session�����Զ��ͷš�
//���⣬��Ҫ��װһ���ͷź�������session��map���Ƴ����������ü���Ϊ0���Զ��ͷ�
void CServer::startAccept()
{
	auto& ioc = AsioIOServicePool::GetInstance()->GetIOService();
	std::shared_ptr<CSession> new_session = std::make_shared<CSession>(ioc, this);
	_acceptor.async_accept(new_session->getSocket(), 
		std::bind(&CServer::HandleAccept, this, new_session, std::placeholders::_1));
	
}
