#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>
#include<string>
#include<functional>

class ThreadPool {
public:
    ThreadPool(int threadCount) : stop(false) {
        for(int i = 0; i < threadCount; i++) {
            threads.emplace_back([this]() {
                while(true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(mtx);
                        cv.wait(lock, [this] { return stop || !tasks.empty(); });
                        if(stop && tasks.empty()) return;     // 如果停止且任务队列为空，退出线程
                        // 使用 std::move 可以把队列中的任务内容直接“搬”到 task，而不是复制一份，提升性能。
                        task = std::move(tasks.front());     
                        tasks.pop();
                    }
                    task();  // 执行任务
                }
            });
                
        }
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(mtx);
            stop = true;  // 设置停止标志
        }
        cv.notify_all();       // 唤醒所有线程
        for(auto& thread : threads) {
            thread.join();     // 等待所有线程结束
        }
    }

    // 提交任务到线程池
    // ... Args 表示可变参数模板，可以接受任意数量的参数  
    // Args... 表示可变参数的类型
    template<class F, class... Args>   
    void enqueue(F&& f, Args&&... args) {
        std::function<void()> task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        {
            std::unique_lock<std::mutex> lock(mtx);
            tasks.emplace(std::move(task));  // 将任务添加到队列
        }
        cv.notify_one();  // 通知一个线程有新任务
    }

private: 
    std::vector<std::thread> threads;  // 线程数组
    std::queue<std::function<void()>> tasks;  // 任务队列
    std::mutex mtx;  // 互斥锁
    std::condition_variable cv;  // 条件变量
    bool stop;
};

std::mutex cout_mtx;  // 用于保护输出流的互斥锁
int main () {
    ThreadPool pool(4);  // 创建一个包含4个线程的线程池

    // 提交一些任务
    for(int i = 0; i < 10; i++) {
        pool.enqueue([i](){    // i可以被复制， 线程池会复制一份  锁不能被复制只能被转移
            {
                std::lock_guard<std::mutex> lock(cout_mtx);
                std::cout << "Task " << i << " is running in thread " << std::this_thread::get_id() << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
            {
                std::lock_guard<std::mutex> lock(cout_mtx);
                std::cout << "Task " << i << " completed in thread " << std::this_thread::get_id() << std::endl;
            }
        });
    }

    return 0;
}
// 线程数组    需要一个任务队列   生产者加任务  线程取任务