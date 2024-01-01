#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::vector<int> primes;  // 存放素数的容器
std::mutex primesMutex;  // 互斥锁，用于保护容器的访问

// 判断一个数是否为素数
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// 计算给定范围内的素数，并将其添加到容器中
void calculatePrimes(int start, int end) {
    std::vector<int> localPrimes;  // 每个线程的局部容器

    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            localPrimes.push_back(i);
        }
    }

    // 将局部容器的内容合并到全局容器中
    std::lock_guard<std::mutex> lock(primesMutex);
    primes.insert(primes.end(), localPrimes.begin(), localPrimes.end());
}

int main() {
    int rangeStart = 1;
    int rangeEnd = 100;

    // 设置线程数量
    int numThreads = std::thread::hardware_concurrency();
    if (numThreads == 0) {
        numThreads = 2;  // 如果硬件无法检测线程数，则设置默认值为2
    }

    // 计算每个线程的工作范围
    int step = (rangeEnd - rangeStart + 1) / numThreads;
    int start = rangeStart;
    int end = start + step - 1;

    // 启动线程
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(calculatePrimes, start, end);
        start = end + 1;
        end = (i == numThreads - 2) ? rangeEnd : end + step;
    }

    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }

    // 输出找到的素数
    std::cout << "Prime numbers in the range [" << rangeStart << ", " << rangeEnd << "] are: ";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}