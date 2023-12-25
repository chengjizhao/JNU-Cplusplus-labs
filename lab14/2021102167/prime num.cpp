#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

bool is_prime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void find_primes(int start, int end, std::vector<int>& result, std::mutex& mtx) {
    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            std::lock_guard<std::mutex> lock(mtx);
            result.push_back(num);
        }
    }
}

int main() {
    const int num_threads = 4;
    std::vector<std::thread> threads;
    std::vector<int> result;
    std::mutex mtx;

    int interval = 1000;
    for (int i = 0; i < num_threads; i++) {
        int start = i * interval + 1;
        int end = (i + 1) * interval;
        threads.emplace_back(find_primes, start, end, std::ref(result), std::ref(mtx));
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Prime numbers found: ";
    for (int prime : result) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}