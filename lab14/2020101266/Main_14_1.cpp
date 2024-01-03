#include <iostream>  
#include <vector>  
#include <thread>  
#include <mutex>  
#include <condition_variable>  

const int MAX_NUM = 10000;
std::vector<bool> isPrime(MAX_NUM, true);
std::mutex mtx;
std::condition_variable cv;
int primeCount = 0;

void checkPrimes(int low, int high) {
    if (low % 2 == 0) {
        isPrime[low] = false;
    }
    for (int i = low * low; i <= high; i += 2) {
        isPrime[i] = false;
    }
    for (int i = low; i <= high; i++) {
        if (isPrime[i]) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [] { return primeCount < MAX_NUM; });
            primes.push_back(i);
            primeCount++;
            lock.unlock();
            cv.notify_one();
        }
    }
}

int main() {
    std::vector<std::thread> threads;
    int low = 2;
    int high = MAX_NUM / 2; // We only need to check half of the numbers since they are all even numbers.  
    while (low <= high) {
        threads.push_back(std::thread(checkPrimes, low, high));
        low += 2; // Check only odd numbers.  
        high += 2; // Check only odd numbers.  
    }
    for (auto& t : threads) {
        t.join();
    }
    std::cout << "Prime count: " << primeCount << std::endl;
    return 0;
}