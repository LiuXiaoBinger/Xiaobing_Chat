#pragma once
#include "const.h"


struct CSectionInfo {
	CSectionInfo() {}
	~CSectionInfo() {
		_section_datas.clear();
	}

	CSectionInfo(const CSectionInfo& src) {
		_section_datas = src._section_datas;
	}

	CSectionInfo& operator = (const CSectionInfo& src) {
		if (&src == this) {
			return *this;
		}

		this->_section_datas = src._section_datas;
		return *this;
	}

	std::map<std::string, std::string> _section_datas;
	std::string  operator[](const std::string& key) {
		if (_section_datas.find(key) == _section_datas.end()) {
			return "";
		}
		// 这里可以添加一些边界检查  
		return _section_datas[key];
	}
};

class m_ConfigDeal
{
public:
	~m_ConfigDeal() {
		_config_map.clear();
	}
	CSectionInfo operator[](const std::string& section) {
		if (_config_map.find(section) == _config_map.end()) {
			return CSectionInfo();
		}
		return _config_map[section];
	}

	static m_ConfigDeal& Inst() {
		static m_ConfigDeal cfg_mgr;
		return cfg_mgr;
	}
	m_ConfigDeal& operator=(const m_ConfigDeal& src) {
		if (&src == this) {
			return *this;
		}

		this->_config_map = src._config_map;
	};

	m_ConfigDeal(const m_ConfigDeal& src) {
		this->_config_map = src._config_map;
	}

	m_ConfigDeal();
private:

	// 存储section和key-value对的map  
	std::map<std::string, CSectionInfo> _config_map;
};