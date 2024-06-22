#pragma once
#include "const.h"
#include "MySqlPool.h"
class CMysqlMgr : public Singleton<CMysqlMgr>
{
	friend class Singleton<CMysqlMgr>;
public:
	~CMysqlMgr();
	int RegUser(const std::string& name, const std::string& email, const std::string& pwd);
	bool CheckEmail(const std::string& name, const std::string& email);
	bool UpdatePwd(const std::string& name, const std::string& email);
	bool CheckPwd(const std::string& email, const std::string& pwd, UserInfo& userInfo);
	bool TestProcedure(const std::string& email, int& uid, std::string& name);
private:
	CMysqlMgr() {

	}
	MysqlDao  _dao;
};

