#include "m_httpServer.h"
#include "HttpConnection.h"
#include "AsioIOServicePool.h"
m_httpServer::m_httpServer(boost::asio::io_context& ioc, unsigned short& port)
	:_ioc(ioc), _acceptor(ioc,tcp::endpoint(tcp::v4(),port)), _socket(ioc)
{

}

void m_httpServer::Start()
{
    //���߳�һ�������ĸ�������socket�������߳������ĸ����д�¼���Ҳ����ζ��http::async_read�����ĵ�������socket�󶨵��������Ǹ��̵߳���
    auto self = shared_from_this();
    boost::asio::io_context& m_io_context = AsioIOServicePool::Get_M_ptr()->GetIOService();
    
    std::shared_ptr<M_HttpConnection> ptr=std::make_shared<M_HttpConnection>(m_io_context);
    _acceptor.async_accept(ptr->getSocket(), [self, ptr](beast::error_code ec) {
        try {
            //���������������ӣ���������������
            if (ec) {
                self->Start();
                return;
            }
            std::cout<<"m_httpServer::Start�߳�id" << std::this_thread::get_id()<<std::endl;
            //���������ӣ�����HpptConnection�����������
            ptr->Start();
            //��������
            self->Start();
        }
        catch (std::exception& exp) {
            std::cout << "exception is " << exp.what() << std::endl;
            self->Start();
        }
        });
}
