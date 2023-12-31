#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cmath>

std::mutex mtx;  // Mutex for protecting shared data access

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    int sqrtNum = static_cast<int>(std::sqrt(num));
    for (int i = 2; i <= sqrtNum; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Thread function to find primes in a range and store them in a container
void findPrimesInRange(int start, int end, std::vector<int>& primes) {
    for (int num = start; num < end; ++num) {
        if (isPrime(num)) {
            std::lock_guard<std::mutex> lock(mtx);  // Use a lock to protect shared data access
            primes.push_back(num);
        }
    }
}

int main() {
    const int rangeStart = 1;
    const int rangeEnd = 100;

    const int numThreads = 4;  // Specify the number of threads
    std::vector<std::thread> threads;
    std::vector<int> primes;

    // Start multiple threads for parallel computation
    for (int i = 0; i < numThreads; ++i) {
        int start = rangeStart + i * (rangeEnd - rangeStart) / numThreads;
        int end = rangeStart + (i + 1) * (rangeEnd - rangeStart) / numThreads;
        threads.emplace_back(findPrimesInRange, start, end, std::ref(primes));
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }

    // Print the found prime numbers
    std::cout << "Prime numbers in the range [" << rangeStart << ", " << rangeEnd << "):" << std::endl;
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
