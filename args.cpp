#include<iostream>
#include<string>

template<typename T>
T sum (const T &a) {
    return a;
}

// 变参的3种展开方法
// 1. 直接展开（用逗号）把包展开成参数列表
// 2. 递归展开
// 3. 折叠表达式（C++17）
template<typename T, typename... Args>
T sum (const T &a,  const Args&... args) {
    return a + sum(args...);
}


void Demo() {
    std::cout << sum(1, 2, 3, 4, 5) << std::endl; // 输出15
    std::cout << sum(1.1, 2.2, 3.3) << std::endl; // 输出6.6
    std::cout << sum(std::string("Hello, "), std::string("World!")) << std::endl; // 输出Hello, World!
}

int main() {
    Demo();
    return 0;
}

//  