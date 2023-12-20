#include <iostream>
#include <vector>
#include <thread>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void calculatePrimes(int start, int end, std::vector<int>& primes) {
    for (int num = start; num <= end; num++) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
    }
}

int main() {
    int rangeStart = 1;
    int rangeEnd = 100;
    int numThreads = 4;  // 可根据需要设置线程数量

    std::vector<int> primes;
    std::vector<std::thread> threads;

    int rangeSize = (rangeEnd - rangeStart + 1) / numThreads;
    int extraRange = (rangeEnd - rangeStart + 1) % numThreads;

    for (int i = 0; i < numThreads; i++) {
        int start = rangeStart + i * rangeSize;
        int end = start + rangeSize - 1;
        if (i == numThreads - 1) {
            end += extraRange;
        }
        threads.push_back(std::thread(calculatePrimes, start, end, std::ref(primes)));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    int sum = 0;
    for (auto prime : primes) {
        sum += prime;
    }

    std::cout << "Sum of primes: " << sum << std::endl;

    return 0;
}
