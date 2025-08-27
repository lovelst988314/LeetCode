#include<iostream>
#include<thread>
#include<memory>

using namespace std;

class A {
public:
    void foo() {
        cout << "hello" << endl;
    }
private: 
    friend void thread_foo();
    void bar() {
        cout << "world" << endl;
    }
};

void thread_foo() {
    shared_ptr<A> a = make_shared<A>();
    thread t(&A::bar, a);

    t.join();
}//  要访问类的私有就需要使用友元函数


int main() {
    shared_ptr<A> a = make_shared<A>(); // 创建一个shared_ptr对象
    a->foo();  // 调用公有方法
    
    // 第一个变量&ClassName::functionName 用于获取成员函数的地址
    // 当传递成员函数指针给线程时，第二个参数必须是该成员函数所属类的对象实例
    thread t1(&A::foo, a); 
    t1.join();

    thread_foo();

    return 0;
}


















//  类和线程配合需要注意的问题