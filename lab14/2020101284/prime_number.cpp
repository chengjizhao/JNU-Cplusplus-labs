#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cmath>
#include <future>
#include <functional>

bool isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

std::mutex resultMutex;
std::vector<int> primeNumbers;

void findPrimesInRange(int start, int end) {
    std::vector<int> primesInRange;
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            primesInRange.push_back(i);
        }
    }
    std::lock_guard<std::mutex> lock(resultMutex);
    primeNumbers.insert(primeNumbers.end(), primesInRange.begin(), primesInRange.end());
}

int main() {
    const int rangeStart = 1;
    const int rangeEnd = 100;

    const int numThreads = std::thread::hardware_concurrency();
    const int step = (rangeEnd - rangeStart + 1) / numThreads;

    std::vector<std::future<void>> futures;

    for (int i = 0; i < numThreads; ++i) {
        int start = rangeStart + i * step;
        int end = (i == numThreads - 1) ? rangeEnd : start + step - 1;

        std::packaged_task<void()> task(std::bind(findPrimesInRange, start, end));
        futures.emplace_back(task.get_future());
        std::thread(std::move(task)).detach();
    }

    for (auto& future : futures) {
        future.wait();
    }

    std::cout << "Prime numbers in the range " << rangeStart << " to " << rangeEnd << " are:" << std::endl;
    for (const auto& prime : primeNumbers) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
