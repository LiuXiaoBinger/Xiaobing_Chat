#include "m_httpServer.h"
#include "HttpConnection.h"
#include "AsioIOServicePool.h"
m_httpServer::m_httpServer(boost::asio::io_context& ioc, unsigned short& port)
	:_ioc(ioc), _acceptor(ioc,tcp::endpoint(tcp::v4(),port)), _socket(ioc)
{

}

void m_httpServer::Start()
{
    //主线程一个上下文负责链接socket，其他线程上下文负责读写事件，也就意味着http::async_read函数的调用是在socket绑定的上下文那个线程调度
    auto self = shared_from_this();
    boost::asio::io_context& m_io_context = AsioIOServicePool::Get_M_ptr()->GetIOService();
    
    std::shared_ptr<M_HttpConnection> ptr=std::make_shared<M_HttpConnection>(m_io_context);
    _acceptor.async_accept(ptr->getSocket(), [self, ptr](beast::error_code ec) {
        try {
            //出错则放弃这个连接，继续监听新链接
            if (ec) {
                self->Start();
                return;
            }
            std::cout<<"m_httpServer::Start线程id" << std::this_thread::get_id()<<std::endl;
            //处理新链接，创建HpptConnection类管理新连接
            ptr->Start();
            //继续监听
            self->Start();
        }
        catch (std::exception& exp) {
            std::cout << "exception is " << exp.what() << std::endl;
            self->Start();
        }
        });
}
