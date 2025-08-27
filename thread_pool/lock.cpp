#include<iostream>
#include<thread>
#include<mutex>

int shared_data = 0;

std::mutex mtx;
void add_to_shared_data()
{
    for(int i = 0; i < 1000000; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx);
        shared_data++;
    }
}

int main()
{
    std::thread t1(add_to_shared_data);
    std::thread t2(add_to_shared_data);
    t1.join();
    t2.join();
    std::cout << shared_data << std::endl;
}


//  std::lock_guard<std::mutex> lock(mtx); mutex的RAII封装，自动加锁和解锁  无法拷贝和赋值
//  std::unique_lock<std::mutex> lock(mtx);  unique_lock可以手动加锁和解锁  可以拷贝和赋值 