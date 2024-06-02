#pragma once
/******************************************************************************
 *
 * @file       CVerifyGrpcClient.h
 * @brief      Grpc�ͻ���ͷ�ļ�
 *
 * @author     ��С����
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
using message::GetVarifyReq;//�����
using message::GetVarifyRsp;//�ظ���
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

