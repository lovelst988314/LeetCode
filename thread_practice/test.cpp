#include "threadpool.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <mutex>
#include <cmath>

std::mutex cout_mutex;

// 判断一个数是否为质数（计算密集型任务）
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(n); i += 2)
        if (n % i == 0) return false;
    return true;
}

int main() {
    // 创建一个包含4个工作线程的线程池
    ThreadPool pool(4);

    // 用于存储任务结果的向量
    std::vector<bool> results(100);  // 检查 100 个数字是否是质数

    // 向线程池中添加100个任务
    for (int i = 0; i < 100; ++i) {
        pool.AddTask([i, &results]() {
            bool result = is_prime(i);
            {
                std::lock_guard<std::mutex> lock(cout_mutex);
                std::cout << "Task " << i << " executed by thread " 
                          << std::this_thread::get_id() 
                          << " - is prime: " << std::boolalpha << result << std::endl;
            }
            results[i] = result;
        });
    }

    // 等待所有任务完成（简单等待，实际应使用 future 或其他同步机制）
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}