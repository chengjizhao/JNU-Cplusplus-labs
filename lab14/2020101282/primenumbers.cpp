#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex resultMutex;
std::vector<int> primeNumbers;

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

void findPrimesInRange(int start, int end) {
    std::vector<int> localPrimes;

    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            localPrimes.push_back(i);
        }
    }

    // 向共享容器中添加本地素数
    std::lock_guard<std::mutex> lock(resultMutex);
    primeNumbers.insert(primeNumbers.end(), localPrimes.begin(), localPrimes.end());
}

int main() {
    const int rangeStart = 1;
    const int rangeEnd = 100;

    const int numThreads = 4;  // 设置线程数量

    std::vector<std::thread> threads;

    // 划分范围并启动线程
    int rangeSize = (rangeEnd - rangeStart + 1) / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        int start = rangeStart + i * rangeSize;
        int end = (i == numThreads - 1) ? rangeEnd : start + rangeSize - 1;
        threads.emplace_back(findPrimesInRange, start, end);
    }

    // 等待所有线程完成
    for (std::thread& thread : threads) {
        thread.join();
    }

    // 输出找到的素数
    std::cout << "Prime numbers in the range [" << rangeStart << ", " << rangeEnd << "] are:\n";
    for (int prime : primeNumbers) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
