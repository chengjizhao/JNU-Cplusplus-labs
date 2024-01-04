#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

// 定义一个共享的原子计数器
std::atomic<int> counter = 0;

// 定义一个互斥锁
std::mutex mtx;

// 定义一个递增计数器的函数
void increment(int n) {
    // 对计数器加锁，防止其他线程访问
    std::lock_guard<std::mutex> lock(mtx);
    // 循环n次，每次递增计数器
    for (int i = 0; i < n; i++) {
        counter++;
    }
}

// 定义一个递减计数器的函数
void decrement(int n) {
    // 对计数器加锁，防止其他线程访问
    std::lock_guard<std::mutex> lock(mtx);
    // 循环n次，每次递减计数器
    for (int i = 0; i < n; i++) {
        counter--;
    }
}

int main() {
    // 创建两个线程，一个递增计数器100次，另一个递减计数器50次
    std::thread t1(increment, 100);
    std::thread t2(decrement, 50);

    // 等待两个线程结束
    t1.join();
    t2.join();

    // 输出最终的计数器值
    std::cout << "Counter = " << counter << std::endl;

    return 0;
}
