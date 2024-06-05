#pragma once
#include <boost/beast/http.hpp>
#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <memory>
#include <iostream>

#include <json/json.h>
#include <json/value.h>
#include <json/reader.h>
#include <queue>
#include <atomic>

enum ErrorCodes {
	Success = 0,
	Error_Json = 1001,  //JsonΩ‚Œˆ¥ÌŒÛ
	RPCFailed = 1002,  //RPC«Î«Û¥ÌŒÛ
};
namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

