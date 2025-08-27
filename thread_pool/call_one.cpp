#include<iostream>
#include<thread>
#include<mutex>
#include<string>

class Log {
public:
    Log() {};
    Log(const Log&) = delete; // 禁止拷贝构造
    Log& operator=(const Log&) = delete; // 禁止赋值操作

    static Log& getinstance() {
        static Log instance; // 懒汉式单例
        return instance;
    }
    void print(const std::string& msg) {
        std::cout << msg << std::endl;
    }
private:
};
// 懒汉模式  只有在第一次使用时才创建实例   如果程序从未使用该实例，则不会创建  
// C++11标准后的线程安全懒汉实现，利用局部静态变量的特性。

// 饿汉模式 程序启动时就创建实例  无需考虑多线程竞争问题  无论是否使用都会占用内存

int main() {
    Log::getinstance().print("hello world");  //全局只有一个 需要使用时用getinstance()获取即可
    return 0;
}