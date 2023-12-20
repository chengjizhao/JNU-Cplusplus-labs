#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void findPrimes(int start, int end, std::vector<int>& primes, std::mutex& mutex)
{
    for (int num = start; num <= end; ++num)
    {
        if (isPrime(num))
        {
            std::lock_guard<std::mutex> lock(mutex);
            primes.push_back(num);
        }
    }
}

int main()
{
    int start = 1;
    int end = 100;

    // 创建多个线程并行计算素数
    std::vector<std::thread> threads;
    std::vector<int> primes;
    std::mutex mutex;

    int numThreads = std::thread::hardware_concurrency(); // 获取可用的线程数
    int range = end - start + 1;
    int chunkSize = range / numThreads;
    int remaining = range % numThreads;

    int threadStart = start;
    int threadEnd = start + chunkSize - 1;

    for (int i = 0; i < numThreads; ++i)
    {
        if (remaining > 0)
        {
            --remaining;
            threadEnd++;
        }

        threads.emplace_back(findPrimes, threadStart, threadEnd, std::ref(primes), std::ref(mutex));

        threadStart = threadEnd + 1;
        threadEnd = threadStart + chunkSize - 1;
    }

    // 等待所有线程执行完毕
    for (auto& thread : threads)
    {
        thread.join();
    }

    // 输出素数
    for (int prime : primes)
    {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}