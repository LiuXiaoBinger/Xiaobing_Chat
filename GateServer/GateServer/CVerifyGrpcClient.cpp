#include "CVerifyGrpcClient.h"

GetVarifyRsp CVerifyGrpcClient::GetVarifyReq_ToGetVarifyRsp(std::string email)
{
	ClientContext context;
	GetVarifyRsp reply;
	GetVarifyReq request;
	request.set_email(email);
	auto stub = pool_->getConnection();
	Status status = stub->GetVarifyCode(&context, request, &reply);

	if (status.ok()) {
		pool_->returnConnection(std::move(stub));
		return reply;
	}
	else {
		pool_->returnConnection(std::move(stub));
		reply.set_error(ErrorCodes::RPCFailed);
		return reply;
	}
}
