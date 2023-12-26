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

void calculatePrimesInRange(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            sum += i;
            std::lock_guard<std::mutex> lock(resultMutex);
            primeNumbers.push_back(i);
        }
    }
    std::cout << "Sum of primes in range [" << start << ", " << end << "]: " << sum << std::endl;
}

int main() {
    const int numThreads = 4; // 设置线程数量
    const int rangeStart = 1;
    const int rangeEnd = 100;

    std::vector<std::thread> threads;

    int rangeSize = (rangeEnd - rangeStart + 1) / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        int start = rangeStart + i * rangeSize;
        int end = (i == numThreads - 1) ? rangeEnd : start + rangeSize - 1;
        threads.emplace_back(calculatePrimesInRange, start, end);
    }

    for (std::thread& t : threads) {
        t.join();
    }

    // 打印所有找到的素数
    std::cout << "Prime numbers found: ";
    for (int prime : primeNumbers) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}