#include "CVerifyGrpcClient.h"

GetVarifyRsp CVerifyGrpcClient::GetVarifyReq_ToGetVarifyRsp(std::string email)
{
    ClientContext context;
    GetVarifyReq req;
    req.set_email(email);
    GetVarifyRsp rsq;
   // (::grpc::ClientContext * context, const ::message::GetVarifyReq & request, ::message::GetVarifyRsp * response) = 0;
    Status status = stub_->GetVarifyCode(&context, req, &rsq);
    if (!status.ok()) {
        rsq.set_error(ErrorCodes::RPCFailed);
        return rsq;
    }
    return rsq;
}
