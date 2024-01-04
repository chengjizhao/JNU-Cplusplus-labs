#include <iostream>
#include <string>
#include <thread>
#include <mutex>

std::mutex counterMutex;  // 互斥锁
int counter = 0;  // 共享计数器

// 递增计数器的线程函数
void incrementCounter(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        std::lock_guard<std::mutex> lock(counterMutex);
        ++counter;
    }
}

// 递减计数器的线程函数
void decrementCounter(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        std::lock_guard<std::mutex> lock(counterMutex);
        --counter;
    }
}

int main() {
    const int incrementIterations = 100;
    const int decrementIterations = 50;

    // 创建两个线程，一个递增计数器，一个递减计数器
    std::thread incrementThread(incrementCounter, incrementIterations);
    std::thread decrementThread(decrementCounter, decrementIterations);

    // 等待两个线程完成
    incrementThread.join();
    decrementThread.join();

    // 输出最终计数器的值
    std::cout << "Final Counter Value: " << counter << std::endl;

    return 0;
}
