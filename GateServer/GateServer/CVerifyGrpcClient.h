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
using grpc::Channel;
using grpc::Status;
using grpc::ClientContext;
using message::GetVarifyReq;//请求包
using message::GetVarifyRsp;//回复包
using message::VarifyService;
class CVerifyGrpcClient :public Singleton<CVerifyGrpcClient>
{
	friend class Singleton<CVerifyGrpcClient>;
public:
	GetVarifyRsp GetVarifyReq_ToGetVarifyRsp( std::string email);
private:
	CVerifyGrpcClient() {
		std::shared_ptr<Channel> channel = grpc::CreateChannel("127.0.0.1:50051", grpc::InsecureChannelCredentials());
		stub_ = VarifyService::NewStub(channel);
	}

	std::unique_ptr<VarifyService::Stub> stub_;

};

