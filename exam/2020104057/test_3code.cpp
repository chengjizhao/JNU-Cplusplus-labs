#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;// 定义一个共享的计数器
std::mutex mtx;// 创建一个互斥锁

// 递增计数器的线程函数
void incrementCounter() {
    for (int i = 0; i < 100; i++) {
        std::lock_guard<std::mutex> lock(mtx); // 加锁
        counter++;
    }
}

// 递减计数器的线程函数
void decrementCounter() {
    for (int i = 0; i < 50; i++) {
        std::lock_guard<std::mutex> lock(mtx); // 加锁
        counter--;
    }
}

int main() {
    // 创建两个线程
    std::thread t1(incrementCounter);
    std::thread t2(decrementCounter);

    // 等待两个线程结束
    t1.join();
    t2.join();

    // 输出最终的计数器值为50
    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}