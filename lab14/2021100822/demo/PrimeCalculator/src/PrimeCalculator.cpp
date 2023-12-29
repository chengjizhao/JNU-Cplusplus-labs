#include "PrimeCalculator.h"

std::mutex g_mutex;
std::vector<int> g_primeNumbers;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void calculatePrimesInRange(int start, int end) {
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            std::lock_guard<std::mutex> lock(g_mutex);
            g_primeNumbers.push_back(i);
        }
    }
}