#include <iostream>
#include <vector>
#include <thread>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void findPrimes(int start, int end, std::vector<int>& primes) {
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
}

int main() {
    int start = 2;
    int end = 100;

    std::vector<int> primes;
    std::thread t1(findPrimes, start, end / 2, std::ref(primes));
    std::thread t2(findPrimes, end / 2 + 1, end, std::ref(primes));

    t1.join();
    t2.join();

    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}