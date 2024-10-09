#pragma once
#include <boost/asio.hpp>
#include "CSession.h"
#include <memory.h>
#include <map>
#include <mutex>
#include <iostream>
//using namespace std;
using boost::asio::ip::tcp;
class CServer
{
public:
	CServer(boost::asio::io_context& ioc, short prot);
	~CServer();
	void clearCSessionData(std::string);
private:
	void HandleAccept(std::shared_ptr<CSession>newCSession, const boost::system::error_code& ec);
	void startAccept();
	boost::asio::io_context& _io_context;
	short _prot;
	tcp::acceptor _acceptor;
	std::map<std::string, std::shared_ptr<CSession>> _sessions;
	std::mutex _mutex;
};

