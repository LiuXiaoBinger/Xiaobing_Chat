#include <iostream>
#include <json/json.h>
#include <json/value.h>
#include <json/reader.h>
#include "m_httpServer.h"
#include "m_ConfigDeal.h"
int main()
{
    auto& gCfgMgr = m_ConfigDeal::Inst();
	std::string gate_port_str = gCfgMgr["GateServer"]["Port"];
	unsigned short gate_port = atoi(gate_port_str.c_str());
    std::cout  <<"主线程id" << std::this_thread::get_id() << std::endl;
    try {
        unsigned short port = static_cast<unsigned short>(gate_port);
        net::io_context ioc{ 1 };//初始化线程数为1
        boost::asio::signal_set signals(ioc, SIGINT, SIGTERM);
        signals.async_wait([&ioc](const boost::system::error_code& error, int signal_number) {
            if (error) {
                return;
            }
            ioc.stop();
            });
        std::make_shared<m_httpServer>(ioc, port)->Start();
        ioc.run();
            
    }
    catch (std::exception const& e) {
        std::cerr << "Error:" << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}