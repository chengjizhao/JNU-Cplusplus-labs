#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <cmath>

bool is_prime(int num) {
   if (num <= 1) {
       return false;
   }
   for (int i = 2; i * i <= num; ++i) {
       if (num % i == 0) {
           return false;
       }
   }
   return true;
}

void find_primes(int start, int end, std::vector<int> &primes, std::mutex &mutex) {
   for (int num = start; num <= end; ++num) {
       if (is_prime(num)) {
           std::lock_guard<std::mutex> lock(mutex);
           primes.push_back(num);
       }
   }
}

int main() {
   int start = 10;
   int end = 50;
   std::vector<int> primes;
   std::mutex mutex;

   const int num_threads = 4;
   std::thread threads[num_threads];

   for (int i = 0; i < num_threads; ++i) {
       int thread_start = start + i * (end - start) / num_threads;
       int thread_end = start + (i + 1) * (end - start) / num_threads;
       threads[i] = std::thread(find_primes, thread_start, thread_end, std::ref(primes), std::ref(mutex));
   }

   for (int i = 0; i < num_threads; ++i) {
       threads[i].join();
   }

   std::cout << "Primes in range [" << start << ", " << end << "]:" << std::endl;
   for (int prime : primes) {
       std::cout << prime << " ";
   }
   std::cout << std::endl;

   return 0;
}
