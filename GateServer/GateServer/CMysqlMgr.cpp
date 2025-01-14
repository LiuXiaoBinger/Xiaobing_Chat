#include "CMysqlMgr.h"

CMysqlMgr::~CMysqlMgr() {

}

int CMysqlMgr::RegUser(const std::string& name, const std::string& email, const std::string& pwd)
{
	return _dao.RegUser(name, email, pwd);
}

bool CMysqlMgr::CheckEmail(const std::string& name, const std::string& email) {
	return _dao.CheckEmail(name, email);
}

bool CMysqlMgr::UpdatePwd(const std::string& name, const std::string& pwd) {
	return _dao.UpdatePwd(name, pwd);
}



bool CMysqlMgr::CheckPwd(const std::string& email, const std::string& pwd, UserInfo& userInfo) {
	return _dao.CheckPwd(email, pwd, userInfo);
}

bool CMysqlMgr::TestProcedure(const std::string& email, int& uid, std::string& name) {
	return _dao.TestProcedure(email, uid, name);
}
