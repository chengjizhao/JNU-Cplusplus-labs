#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// 全局变量用于存放素数
std::vector<int> primes;

// 互斥锁，用于在向容器中添加素数时保护共享资源
std::mutex primesMutex;

// 判断一个数是否为素数
bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

// 线程函数，找出给定范围内的素数并添加到容器
void findPrimesInRange(int start, int end)
{
    for (int i = start; i <= end; ++i)
    {
        if (isPrime(i))
        {
            std::lock_guard<std::mutex> lock(primesMutex);
            primes.push_back(i);
        }
    }
}

int main()
{
    const int rangeStart = 1;
    const int rangeEnd = 100;

    const int numThreads = 4; // 设置线程数量

    // 计算每个线程处理的范围大小
    int rangeSize = (rangeEnd - rangeStart + 1) / numThreads;

    // 创建线程
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i)
    {
        int start = rangeStart + i * rangeSize;
        int end = (i == numThreads - 1) ? rangeEnd : start + rangeSize - 1;
        threads.emplace_back(findPrimesInRange, start, end);
    }

    // 等待所有线程完成
    for (auto &thread : threads)
    {
        thread.join();
    }

    // 输出结果
    std::cout << "Prime numbers in the range [" << rangeStart << ", " << rangeEnd << "] are:\n";
    for (int prime : primes)
    {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
