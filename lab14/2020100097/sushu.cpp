#include <iostream>  
#include <vector>  
#include <thread>  
#include <mutex>  
  
std::vector<int> prime_sum;  
std::mutex mtx; 
    
bool is_prime(int num) {  
    if (num < 2) return false;  
    for (int i = 2; i * i <= num; i++) {  
        if (num % i == 0) return false;  
    }  
    return true;  
}  
  
void calc_primes(int start, int end) {  
    int sum = 0;  
    for (int i = start; i <= end; i++) {  
        if (is_prime(i)) {  
            sum += i;  
        }  
    }   
    mtx.lock();  
    prime_sum.push_back(sum);  
    mtx.unlock();  
}  
  
int main() {  
    int lower = 1; 
    int upper = 20000;   
    int num_threads = std::thread::hardware_concurrency();  
    std::vector<std::thread> threads;   
    int range = (upper - lower + 1) / num_threads;  
    for (int i = 0; i < num_threads - 1; i++) {  
        int start = lower + i * range;  
        int end = std::min(start + range, upper);  
        threads.push_back(std::thread(calc_primes, start, end));  
    }  
    int start = lower + (num_threads - 1) * range;  
    int end = std::max(start + range - 1, upper);  
    threads.push_back(std::thread(calc_primes, start, end));   
    for (auto& t : threads) {  
        t.join();  
    }  
    std::cout << "Sum of prime numbers between " << lower << " and " << upper << " is: ";  
    for (auto& sum : prime_sum) {  
        std::cout << sum << " ";  
    }  
    std::cout << std::endl;  
    return 0;  
}