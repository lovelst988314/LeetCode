#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <functional>
#include <cassert>
class ThreadPool {
public:
    explicit ThreadPool(size_t threadCount = 8): pool_(std::make_shared<Pool>()) {
            assert(threadCount > 0);
            for(size_t i = 0; i < threadCount; i++) {
                threads_.emplace_back([pool = pool_] {
                    std::unique_lock<std::mutex> locker(pool->mtx);
                    while(true) {
                        if(!pool->tasks.empty()) {
                            auto task = std::move(pool->tasks.front());
                            pool->tasks.pop();
                            locker.unlock();
                            task();
                            locker.lock();
                        } 
                        else if(pool->isClosed) break;
                        else pool->cond.wait(locker);
                    }
                });
            }
    }

    ThreadPool() = default;  //允许默认构造一个线程池对象，此时不会创建任何工作线程。 

    ThreadPool(ThreadPool&&) = default;  //允许移动构造一个线程池对象。
    
    ~ThreadPool() {
        if(static_cast<bool>(pool_)) {
            {
                std::lock_guard<std::mutex> locker(pool_->mtx);
                pool_->isClosed = true;
            }
            pool_->cond.notify_all();
            for (auto &t : threads_) {
                if (t.joinable()) t.join();    // 等待所有线程完成
            }
        }
    }

    template<class F>
    void AddTask(F&& task) {
        {
            std::lock_guard<std::mutex> locker(pool_->mtx);
            pool_->tasks.emplace(std::forward<F>(task));   //实现了完美转发，支持传递任意类型的可调用对象
        }
        pool_->cond.notify_one();
    }

private:
    struct Pool {
        std::mutex mtx;  // 互斥锁，保护任务队列的访问
        std::condition_variable cond;  // 条件变量，用于线程间的同步
        bool isClosed;  // 标志线程池是否已关闭
        std::queue<std::function<void()>> tasks;  // 任务队列，存储待执行的任务
    };
    std::shared_ptr<Pool> pool_;  // 使用智能指针管理线程池资源
    std::vector<std::thread> threads_;  // 保存工作线程
};


#endif //THREADPOOL_H