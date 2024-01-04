#include <iostream>
#include <mutex>
#include <thread>
/*学号2021102148
高级题目（（4+8）mod 4）+1=1
*/
// 共享计数器类
class Counter
{
private:
    int count;
    std::mutex mutex; // 互斥锁用于保护计数器的并发访问

public:
    Counter() : count(0) {}

    // 递增计数器
    void increment()
    {
        std::lock_guard<std::mutex> lock(mutex); // 使用锁保护临界区
        count++;
    }

    // 递减计数器
    void decrement()
    {
        std::lock_guard<std::mutex> lock(mutex); // 使用锁保护临界区
        count--;
    }

    // 获取当前计数器值
    int getValue() const
    {
        return count;
    }
};

// 递增线程函数
void incrementThread(Counter &counter, int n)
{
    for (int i = 0; i < n; ++i)
    {
        counter.increment();
    }
}

// 递减线程函数
void decrementThread(Counter &counter, int n)
{
    for (int i = 0; i < n; ++i)
    {
        counter.decrement();
    }
}

int main()
{
    Counter counter;

    // 创建两个线程，一个递增计数器100次，另一个递减计数器50次
    std::thread incThread(incrementThread, std::ref(counter), 100);
    std::thread decThread(decrementThread, std::ref(counter), 50);

    // 等待线程执行完毕
    incThread.join();
    decThread.join();

    // 输出最终计数器值
    std::cout << "Final Counter Value: " << counter.getValue() << std::endl;

    return 0;
}