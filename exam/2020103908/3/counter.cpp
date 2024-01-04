/*这个程序中，我们使用了<thread>和<mutex>标准库，创建了一个共享的整数 sharedCounter，并用 std::mutex 中的互斥锁 counterMutex 确保对其的并发访问是线程安全的。incrementCounter 和 decrementCounter 函数分别用于递增和递减计数器。
std::lock_guard 用于管理互斥锁的加锁和解锁，在其作用域结束时自动释放锁，确保线程安全。两个线程分别执行递增和递减操作，最后在 main() 函数中输出最终的计数器值。*/
#include <iostream>
#include <thread>
#include <mutex>

std::mutex counterMutex;
int sharedCounter = 0;

void incrementCounter(int times) {
    for (int i = 0; i < times; ++i) {
        std::lock_guard<std::mutex> lock(counterMutex);  // 互斥锁保护共享资源
        ++sharedCounter;
    }
}

void decrementCounter(int times) {
    for (int i = 0; i < times; ++i) {
        std::lock_guard<std::mutex> lock(counterMutex);  // 互斥锁保护共享资源
        --sharedCounter;
    }
}

int main() {
    const int incrementTimes = 100;
    const int decrementTimes = 50;

    std::thread incrementThread(incrementCounter, incrementTimes);
    std::thread decrementThread(decrementCounter, decrementTimes);

    incrementThread.join();
    decrementThread.join();

    std::cout << "Final Counter Value: " << sharedCounter << std::endl;

    return 0;
}
