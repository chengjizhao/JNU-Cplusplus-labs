#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void findPrimes(int start, int end, std::vector<int>& result, std::mutex& mtx) {
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            std::lock_guard<std::mutex> lock(mtx);
            result.push_back(i);
        }
    }
}

int main() {
    const int numThreads = 5;
    const int range = 1000;
    std::vector<int> primes;
    std::vector<std::thread> threads;
    std::mutex mtx;

    int step = range / numThreads;
    for (int i = 0; i < numThreads; i++) {
        int start = i * step + 1;
        int end = (i == numThreads - 1) ? range : (i + 1) * step;
        threads.push_back(std::thread(findPrimes, start, end, std::ref(primes), std::ref(mtx));
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Prime numbers from 0 to 1000: ";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
