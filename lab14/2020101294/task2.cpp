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

    // ��ȡ�û�����ķ�Χ
    std::cout << "��������ʼ��Χ: ";
    std::cin >> startRange;

    std::cout << "�����������Χ: ";
    std::cin >> endRange;

    // ������뻺����
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // ����Ӳ���������������߳���
    const int numThreads = std::thread::hardware_concurrency();
    std::cout << "ʹ���߳���: " << numThreads << std::endl;

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

    std::cout << "������Χ���������ܺ�Ϊ: " << totalSum << std::endl;

    // ��ӵȴ��û���������Ĵ���
    std::cout << "��������˳�����..." << std::endl;
    std::cin.get();  // �ȴ��û�����

    return 0;
}