#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cmath>

std::mutex mutex;
std::vector<int> primes;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void find_primes(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            std::lock_guard<std::mutex> lock(mutex);
            primes.push_back(i);
        }
    }
}

int main() {
    int start = 2, end = 1000;
    int num_threads = 10;
    std::vector<std::thread> threads;

    // 分割任务
    int step = (end - start + 1) / num_threads;
    for (int i = 0; i < num_threads; i++) {
        int thread_start = start + i * step;
        int thread_end = (i == num_threads - 1) ? end : (thread_start + step - 1);
        threads.push_back(std::thread(find_primes, thread_start, thread_end));
    }

    // 等待所有线程完成
    for (std::thread &t : threads) {
        t.join();
    }

    // 输出素数
    for (int prime : primes) {
        std::cout << prime << " ";
    }

    return 0;
}