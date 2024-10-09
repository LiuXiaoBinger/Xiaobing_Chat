#pragma once
#include "singleton.h"
#include "const.h"
#include "hiredis.h"

#include "CRedisConPool.h"
class CRedisMgr : public Singleton<CRedisMgr>,
	public std::enable_shared_from_this<CRedisMgr>
{
	friend class Singleton<CRedisMgr>;
public:
	~CRedisMgr();
	bool Get(const std::string& key, std::string& value);
	bool Set(const std::string& key, const std::string& value);
	bool LPush(const std::string& key, const std::string& value);
	bool LPop(const std::string& key, std::string& value);
	bool RPush(const std::string& key, const std::string& value);
	bool RPop(const std::string& key, std::string& value);
	bool HSet(const std::string& key, const std::string& hkey, const std::string& value);
	bool HSet(const char* key, const char* hkey, const char* hvalue, size_t hvaluelen);
	std::string HGet(const std::string& key, const std::string& hkey);
	bool HDel(const std::string& key, const std::string& field);
	bool Del(const std::string& key);
	bool ExistsKey(const std::string& key);
	void Close() {
		_con_pool->Close();
		_con_pool->ClearConnections();
	}
private:
	CRedisMgr();
	std::unique_ptr<CRedisConPool>  _con_pool;
	
};

