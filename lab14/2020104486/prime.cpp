#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

bool isPrime(int num) {
 if (num <=1) {
 return false;
 }
 for (int i =2; i * i <= num; ++i) {
 if (num % i ==0) {
 return false;
 }
 }
 return true;
}

void calculatePrimes(int start, int end, std::vector<int>& primes, std::mutex& mtx) {
 int sum =0;
 for (int num = start; num <= end; ++num) {
 if (isPrime(num)) {
 sum += num;
 }
 }
 std::lock_guard<std::mutex> lock(mtx);
 primes.push_back(sum);
}

int main() {
 int rangeStart =1;
 int rangeEnd =100;
 int numThreads =4;

 std::vector<int> primes;
 std::mutex mtx;

 std::vector<std::thread> threads;
 int step = (rangeEnd - rangeStart +1) / numThreads;
 int start = rangeStart;
 int end = start + step -1;

 for (int i =0; i < numThreads; ++i) {
 if (i == numThreads -1) {
 end = rangeEnd;
 }
 threads.emplace_back(calculatePrimes, start, end, std::ref(primes), std::ref(mtx));
 start = end +1;
 end = start + step -1;
 }

 for (auto& thread : threads) {
 thread.join();
 }

 int sum =0;
 for (int primeSum : primes) {
 sum += primeSum;
 }

 std::cout << "Sum of primes: " << sum << std::endl;

 return 0;
}
