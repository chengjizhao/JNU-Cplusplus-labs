#include <iostream>  
#include <vector>  
#include <thread>  
#include <mutex>  
std::mutex mtx;  
std::vector<int> primes;   
bool isPrime(int num) {  
    if (num <= 1) return false;  
    if (num == 2) return true;  
    if (num % 2 == 0) return false;  
    for (int i = 3; i * i <= num; i += 2) {  
        if (num % i == 0) return false;  
    }  
    return true;  
}  
  
void findPrimes(int start, int end) {  
    for (int i = start; i <= end; ++i) {  
        if (isPrime(i)) {   
            mtx.lock();  
            primes.push_back(i);  
            mtx.unlock();  
        }  
    }  
}  
  
int main() {  
    int l = 1;   
    int u = 500;  
    int numThreads = 4;      
    int step = std::max(1, (u-l+1)/numThreads);  
    std::vector<std::thread> threads;  
    for (int i = 0; i < numThreads; ++i) {  
        int start = l+i*step;  
        int end = std::min(start + step,u);  
        threads.push_back(std::thread(findPrimes,start,end));  
    }   
    for (auto& t : threads) {  
        t.join();  
    }    
    std::cout << "在数" << l << " 到数 " << u << " 之间的素数是 ";  
    for (int prime : primes) {  
        std::cout << prime << " ";  
    }  
    std::cout << std::endl;  
    return 0;  
}