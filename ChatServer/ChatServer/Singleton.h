#pragma once
#include <memory>
#include <mutex>
#include <iostream>
//µ¥Àý»ùÀà
template <typename T>
class Singleton
{
protected:
	Singleton() = default;
	Singleton(const Singleton<T>&) = delete;
	Singleton& operator=(const Singleton<T>& st)= delete;

	static std::shared_ptr<T> _instance;
public:
	static std::shared_ptr<T> GetInstance() {
		static std::once_flag flag;
		std::call_once(flag, []() {
			_instance = std::shared_ptr<T>(new T);
			});
		return _instance;
	}
	void PrintAddress() {
		std::cout << _instance.get() << std::endl;
	}
	~Singleton() {
		std::cout << "this is singleton destruct" << std::endl;
	}
};
template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;