#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

// 判断一个数是否为素数
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void calculatePrimeSum(int start, int end, std::vector<int>& primes, std::mutex& mtx) {
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            sum += i;
        }
    }

    std::lock_guard<std::mutex> lock(mtx);
    primes.push_back(sum);
}

int main() {
    const int rangeStart = 1;
    const int rangeEnd = 1000;
    const int numThreads = 4;

    int step = (rangeEnd - rangeStart + 1) / numThreads;
    std::vector<std::thread> threads;
    std::vector<int> partialSums(numThreads, 0);
    std::mutex mtx;

    for (int i = 0; i < numThreads; ++i) {
        int start = rangeStart + i * step;
        int end = (i == numThreads - 1) ? rangeEnd : start + step - 1;

        threads.emplace_back(calculatePrimeSum, start, end, std::ref(partialSums), std::ref(mtx));
    }

    for (auto& t : threads) {
        t.join();
    }

    int totalSum = 0;
    for (auto sum : partialSums) {
        totalSum += sum;
    }

    std::cout << "Total sum of prime numbers within the range: " << totalSum << std::endl;

    return 0;
}