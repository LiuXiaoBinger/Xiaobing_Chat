#pragma once
/******************************************************************************
 *
 * @file       CVerifyGrpcClient.h
 * @brief      Grpc客户端头文件
 *
 * @author     刘小饼儿
 * @date       2024/06/02
 * @history
 *****************************************************************************/
#include "singleton.h"
#include "const.h"
#include <grpcpp/grpcpp.h>
#include "message.grpc.pb.h"
#include "m_ConfigDeal.h"
using grpc::Channel;
using grpc::Status;
using grpc::ClientContext;
using message::GetVarifyReq;//请求包
using message::GetVarifyRsp;//回复包
using message::VarifyService;

class RPConPool {
public:
	RPConPool(size_t poolSize, std::string host, std::string port)
		: poolSize_(poolSize), host_(host), port_(port), b_stop_(false) {
		for (size_t i = 0; i < poolSize_; ++i) {

			std::shared_ptr<Channel> channel = grpc::CreateChannel(host + ":" + port,
				grpc::InsecureChannelCredentials());

			connections_.push(VarifyService::NewStub(channel));
		}
	}

	~RPConPool() {
		std::lock_guard<std::mutex> lock(mutex_);
		Close();
		while (!connections_.empty()) {
			connections_.pop();
		}
	}

	std::unique_ptr<VarifyService::Stub> getConnection() {
		std::unique_lock<std::mutex> lock(mutex_);
		cond_.wait(lock, [this] {
			if (b_stop_) {
				return true;
			}
			return !connections_.empty();
			});
		//如果停止则直接返回空指针
		if (b_stop_) {
			return  nullptr;
		}
		auto context = std::move(connections_.front());
		connections_.pop();
		return context;
	}

	void returnConnection(std::unique_ptr<VarifyService::Stub> context) {
		std::lock_guard<std::mutex> lock(mutex_);
		if (b_stop_) {
			return;
		}
		connections_.push(std::move(context));
		cond_.notify_one();
	}

	void Close() {
		b_stop_ = true;
		cond_.notify_all();
	}

private:
	std::atomic<bool> b_stop_;
	size_t poolSize_;
	std::string host_;
	std::string port_;
	std::queue<std::unique_ptr<VarifyService::Stub>> connections_;
	std::mutex mutex_;
	std::condition_variable cond_;
};
class CVerifyGrpcClient :public Singleton<CVerifyGrpcClient>
{
	friend class Singleton<CVerifyGrpcClient>;
public:
	GetVarifyRsp GetVarifyReq_ToGetVarifyRsp( std::string email);
private:
	CVerifyGrpcClient() {
		auto& gCfgMgr = m_ConfigDeal::Inst();
		std::string host = gCfgMgr["VarifyServer"]["Host"];
		std::string port = gCfgMgr["VarifyServer"]["Port"];
		pool_.reset(new RPConPool(5, host, port));
	}
	std::unique_ptr<RPConPool> pool_;

};

