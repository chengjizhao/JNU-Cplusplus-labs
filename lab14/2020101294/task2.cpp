#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cmath>

std::mutex resultMutex;
std::vector<long long> resultContainer;

bool isPrime(long long num) {
    if (num < 2) {
        return false;
    }
    for (long long i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void calculatePrimesSum(long long start, long long end) {
    long long sum = 0;
    for (long long num = start; num <= end; ++num) {
        if (isPrime(num)) {
            sum += num;
        }
    }

    // Lock the mutex before modifying the shared container
    std::lock_guard<std::mutex> lock(resultMutex);
    resultContainer.push_back(sum);
}

int main() {
    long long startRange, endRange;

    // 获取用户输入的范围
    std::cout << "请输入起始范围: ";
    std::cin >> startRange;

    std::cout << "请输入结束范围: ";
    std::cin >> endRange;

    // 清空输入缓冲区
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // 计算硬件核心数并设置线程数
    const int numThreads = std::thread::hardware_concurrency();
    std::cout << "使用线程数: " << numThreads << std::endl;

    std::vector<std::thread> threads;
    
    // Split the range into equal parts for each thread
    long long step = (endRange - startRange + 1) / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        long long threadStart = startRange + i * step;
        long long threadEnd = threadStart + step - 1;
        threads.emplace_back(calculatePrimesSum, threadStart, threadEnd);
    }

    // Wait for all threads to finish
    for (std::thread& thread : threads) {
        thread.join();
    }

    // Sum the results from all threads
    long long totalSum = 0;
    for (long long sum : resultContainer) {
        totalSum += sum;
    }

    std::cout << "给定范围内素数的总和为: " << totalSum << std::endl;

    // 添加等待用户按任意键的代码
    std::cout << "按任意键退出程序..." << std::endl;
    std::cin.get();  // 等待用户按键

    return 0;
}