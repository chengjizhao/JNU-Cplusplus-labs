#include <iostream>  
#include <queue>  
#include <thread>  
#include <mutex>  
#include <condition_variable>  
#include <random>  
#include <chrono>  
  
std::queue<int> dataQueue;  
std::mutex mtx;  
std::condition_variable cv;  
  
const int maxSize = 20;  
  
void producerThread() {  
    std::mt19937 rng(std::random_device{}());  
    for (int i = 0; i < 10; ++i) { // 生产10个数据  
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 生产者线程每秒生产3个数据，这里简化为每秒生产一个数据  
        std::unique_lock<std::mutex> lock(mtx);  
        dataQueue.push(i); // 生产数据并添加到队列中  
        if (dataQueue.size() == maxSize) {  
            cv.notify_all(); // 当队列满时，通知所有等待的消费者线程  
        } else {  
            cv.wait(lock, []{ return dataQueue.size() == maxSize; }); // 当队列不满时，等待直到队列满或被其他线程唤醒  
        }  
    }  
}  
  
void consumerThread() {  
    std::mt19937 rng(std::random_device{}());  
    while (true) { // 消费者线程无限循环消费数据，这里为了演示简单起见，只消费10个数据  
        std::unique_lock<std::mutex> lock(mtx);  
        cv.wait(lock, []{ return !dataQueue.empty(); }); // 当队列为空时，等待直到队列中有数据或被其他线程唤醒  
        int data = dataQueue.front(); // 取出队列中的数据  
        dataQueue.pop(); // 从队列中移除数据  
        lock.unlock(); // 解锁，允许其他线程访问数据队列  
        std::cout << "Consumer consumed: " << data << std::endl; // 输出消费的数据  
        std::this_thread::sleep_for(std::chrono::seconds(rng() % 2 + 1)); // 随机等待1或2秒后再取下一个数据  
    }  
}  
  
int main() {  
    std::thread producer(producerThread); // 创建生产者线程  
    std::thread consumers[4]; // 创建4个消费者线程  
    for (int i = 0; i < 4; ++i) {  
        consumers[i] = std::thread(consumerThread); // 创建消费者线程  
    }  
    producer.join(); // 等待生产者线程结束  
    for (int i = 0; i < 4; ++i) {  
        consumers[i].join(); // 等待所有消费者线程结束  
    }  
    return 0;  
}