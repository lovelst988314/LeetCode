#include<iostream>
#include<thread>
#include<mutex>

int a = 0;
std::mutex mtx;

void fun1() {
    for(int i = 0; i < 1000000; ++i) {
        mtx.lock();
        a += 1;
        mtx.unlock();
    }
}

int main () {
    std::thread t1(fun1);
    std::thread t2(fun1);
    t1.join();
    t2.join();
    std::cout << a << std::endl;
    return 0;
    
}