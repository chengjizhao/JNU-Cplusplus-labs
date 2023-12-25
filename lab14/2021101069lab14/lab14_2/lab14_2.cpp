#include <iostream>  
#include <vector>  
#include <thread>  
#include <mutex>  
  
// 声明一个互斥锁以保护对共享数据的访问  
std::mutex mtx;  
  
// 声明一个容器来存储找到的素数  
std::vector<int> primes;  
  
// 函数用于检查一个数是否是素数  
bool isPrime(int num) {  
    if (num <= 1) return false;  
    if (num == 2) return true;  
    if (num % 2 == 0) return false;  
    for (int i = 3; i * i <= num; i += 2) {  
        if (num % i == 0) return false;  
    }  
    return true;  
}  
  
// 线程函数，用于在给定范围内找出素数  
void findPrimes(int start, int end) {  
    for (int i = start; i <= end; ++i) {  
        if (isPrime(i)) {  
            // 使用互斥锁来保护对共享数据的访问  
            mtx.lock();  
            primes.push_back(i);  
            mtx.unlock();  
        }  
    }  
}  
  
int main() {  
    int lower = 100;  // 素数查找的起始范围  
    int upper = 500;   // 素数查找的结束范围  
    int numThreads = 4;  // 使用的线程数量  
  
    // 将查找范围分成多个部分，每个线程处理一部分  
    int step = std::max(1, (upper - lower + 1) / numThreads);  
    std::vector<std::thread> threads;  // 存储所有线程的向量  
    for (int i = 0; i < numThreads; ++i) {  
        int start = lower + i * step;  
        int end = std::min(start + step, upper);  
        threads.push_back(std::thread(findPrimes, start, end));  
    }  
    // 等待所有线程完成  
    for (auto& t : threads) {  
        t.join();  
    }  
    // 输出找到的素数  
    std::cout << "Prime numbers between " << lower << " and " << upper << " are: ";  
    for (int prime : primes) {  
        std::cout << prime << " ";  
    }  
    std::cout << std::endl;  
    return 0;  
}