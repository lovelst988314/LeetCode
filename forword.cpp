#include <iostream>
#include <utility> // 包含std::forward
#include <string>

// 模拟一个需要处理左值和右值的类
class DataProcessor {
public:
    // 处理左值字符串（会产生拷贝）
    void handle(std::string& str) {
        std::cout << "[左值处理] 拷贝字符串: " << str << " (内存地址: " << &str << ")\n";
    }

    // 处理右值字符串（会触发移动，无拷贝）
    void handle(std::string&& str) {
        std::cout << "[右值处理] 移动字符串: " << str << " (内存地址: " << &str << ")\n";
    }
};

// 1. 没有完美转发的包装函数
template <typename T>
void bad_forwarder(T arg) {
    DataProcessor processor;
    // 无论原始参数是左值还是右值，arg都是左值
    processor.handle(arg); 
}

// 2. 有完美转发的包装函数
template <typename T>
void good_forwarder(T&& arg) {
    DataProcessor processor;
    // 保持原始参数的值类别（左值/右值）
    processor.handle(std::forward<T>(arg)); 
}

int main() {
    std::string left_val = "左值字符串"; // 左值
    std::cout << "原始左值地址: " << &left_val << "\n\n";

    // 测试无完美转发的情况
    std::cout << "=== 无完美转发 ===" << std::endl;
    std::cout << "1. 传递左值: ";
    bad_forwarder(left_val); // 本应是左值处理（正确）
    
    std::cout << "2. 传递右值: ";
    bad_forwarder(std::string("临时右值字符串")); // 错误转为左值处理

    // 测试有完美转发的情况
    std::cout << "\n=== 有完美转发 ===" << std::endl;
    std::cout << "1. 传递左值: ";
    good_forwarder(left_val); // 正确保持左值属性
    
    std::cout << "2. 传递右值: ";
    good_forwarder(std::string("临时右值字符串")); // 正确保持右值属性
    
    std::cout << "3. 传递std::move左值: ";
    good_forwarder(std::move(left_val)); // 正确转为右值处理

    return 0;
}
