#pragma once
#include "singleton.h"
#include "const.h"
#include "hiredis.h"
class CRedisMgr : public Singleton<CRedisMgr>,
	public std::enable_shared_from_this<CRedisMgr>
{
	friend class Singleton<CRedisMgr>;
public:
	~CRedisMgr();
	bool Connect(const std::string& host, int port);
	bool Get(const std::string& key, std::string& value);
	bool Set(const std::string& key, const std::string& value);
	bool Auth(const std::string& password);
	bool LPush(const std::string& key, const std::string& value);
	bool LPop(const std::string& key, std::string& value);
	bool RPush(const std::string& key, const std::string& value);
	bool RPop(const std::string& key, std::string& value);
	bool HSet(const std::string& key, const std::string& hkey, const std::string& value);
	bool HSet(const char* key, const char* hkey, const char* hvalue, size_t hvaluelen);
	std::string HGet(const std::string& key, const std::string& hkey);
	bool Del(const std::string& key);
	bool ExistsKey(const std::string& key);
	void Close();
private:
	CRedisMgr() {

	}

	redisContext* _connect;
	redisReply* _reply;
};

