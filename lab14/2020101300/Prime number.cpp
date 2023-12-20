#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

// 判断一个数是否为素数
bool is_prime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// 在给定范围内找出素数，并存放到容器中
void find_primes(int start, int end, std::vector<int>& result, std::mutex& mtx) {
    for (int num = start; num < end; ++num) {
        if (is_prime(num)) {
            std::lock_guard<std::mutex> lock(mtx);
            result.push_back(num);
        }
    }
}

int main() {
    const int start_range = 1;
    const int end_range = 100;

    // 使用两个线程来并行计算
    std::vector<int> primes;
    std::mutex primes_mutex;

    // 创建两个线程，每个线程计算一半的范围
    std::thread thread1(find_primes, start_range, end_range / 2, std::ref(primes), std::ref(primes_mutex));
    std::thread thread2(find_primes, end_range / 2, end_range, std::ref(primes), std::ref(primes_mutex));

    // 等待两个线程完成
    thread1.join();
    thread2.join();

    // 输出结果
    std::cout << "所有素数: ";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
