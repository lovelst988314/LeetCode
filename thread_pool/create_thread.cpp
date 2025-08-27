#include<iostream>
#include<thread>

using namespace std;

void thread_func(string name) {
    cout << "Hello from thread " << this_thread::get_id() << endl;
}

int main() {
    // 创建一个线程
    thread t([]() {
        cout << "Hello from thread " << this_thread::get_id() << endl;
    });

    thread t1(thread_func, "t1");

    if(t1.joinable()) {
        t1.join();  // t1.detach();  与主线程分离
    }

    cout << "Hello from main thread " << this_thread::get_id() << endl;

    // 等待线程完成  
    if(t.joinable()) {
        t.join(); // 主程序检查线程是否完成
    }

    cout << "Hello from main thread " << this_thread::get_id() << endl;

    return 0;
}

// 建立一个线程  thread t([]() {cout << "Hello from thread " << this_thread::get_id() << endl;});  lambda表达式或者函数指针
// t.join(); // 等待线程完成  会阻塞主线程直到t完成
// t.detach(); // 与主线程分离
// t.joinable(); // 检查线程是否完成
// t.get_id(); // 获取线程ID