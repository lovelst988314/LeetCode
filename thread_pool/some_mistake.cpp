#include<iostream>
#include<thread>

using namespace std;

void foo(int& x) {
    x += 1;
}

int main() {
    int a = 1;
    thread t(foo, ref(a));  //如果进程中需要传递引用，需要使用std::ref包装
    t.join();

    cout << a << endl;
    return 0;
}

//  thread t(foo, ref(a));  如果进程中需要传递引用，需要使用std::ref包装
//  线程在访问的变量生命周期内完成执行，避免悬空引用。      进程执行完成前，传递的变量都要在生命周期内


