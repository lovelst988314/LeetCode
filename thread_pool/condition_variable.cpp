#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>

std::queue<int> q;
std::condition_variable cv;
std::mutex mtx;
bool finished = false;  // 用于标记生产者是否完成生产

void producter() {
    for(int i = 0; i < 10; i++) {
        std::unique_lock<std::mutex> lock(mtx);
        q.push(i);
        // 唤醒等待的消费者线程
        cv.notify_one();  // 通知一个等待的线程
        std::cout << "Produced: " << i << std::endl;
    } 

    {
        std::lock_guard<std::mutex> lock(mtx);
        finished = true;
        cv.notify_all();  // 通知所有等待的线程
    }
}

void consumer() {
    while(1) {
        std::unique_lock<std::mutex> lock(mtx);

        // 队列为空则要等待
        cv.wait(lock, [](){ return !q.empty() || finished;});  // 第二个变量为true则不堵塞  
        if(finished && q.empty()) {
            break;     // 如果生产者已经完成且队列为空，退出循环
        }
        int val = q.front();
        q.pop();
        std::cout << "Consumed: " << val << std::endl;
    }
}

int main() {
    std::thread t1(producter);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}














// 生产者 消费者模型