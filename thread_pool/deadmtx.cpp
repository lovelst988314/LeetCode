#include<iostream>
#include<thread>
#include<mutex>

int a = 0;
std::mutex mtx1, mtx2;

void fun1() {
    mtx1.lock();
    mtx2.lock();
    mtx1.unlock();
    mtx2.unlock();
}

void fun2() {
    mtx2.lock();
    mtx1.lock();
    mtx2.unlock();
    mtx1.unlock();
}

int main () {
    std::thread t1(fun1);
    std::thread t2(fun2);
    t1.join();
    t2.join();
    std::cout << a << std::endl;
    return 0;
    
}
// 死锁 