#ifndef SINGLETON_H
#define SINGLETON_H
/******************************************************************************
 *
 * @file       singleton.h
 * @brief      单列类
 *
 * @author     刘小饼儿
 * @date       2024/05/29
 * @history
 *****************************************************************************/
#include <memory>
#include<mutex>
#include<iostream>
template<typename T>
class Singleton{
protected:
    Singleton()=default;//构造写成保护，让子类调用，避免外部调用。
    Singleton(const Singleton<T>&)=delete ;
    Singleton& operator=(const Singleton<T>& st) = delete;
    static std::shared_ptr<T> m_ptr;
public:
    static std::shared_ptr<T> Get_M_ptr(){
        //c++11 引入了 std::call_once，通过传入的std::once_flag来确保函数在多线程环境下只被执行一次
        static std::once_flag m_flag;
        std::call_once(m_flag,[&](){
            //不用make_shared 是因为继承的子类的构造函数要设置私有 make_shared无法访问私有构造
            m_ptr=std::shared_ptr<T>(new T);
        });
        return m_ptr;
    }
    void PrintAddress() {
           std::cout << m_ptr.get() <<std:: endl;
       }
       ~Singleton() {
           std::cout << "this is singleton destruct" << std::endl;
       }
};
template<typename T>
std::shared_ptr<T>Singleton<T>:: m_ptr=nullptr;
#endif // SINGLETON_H
