#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
vector<int> primes;

int Prime(int n) 
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void find_primes(int start, int end) 
{
    for (int i = start; i <= end; ++i) {
        if (Prime(i) == 1) 
        {
            lock_guard<mutex> lock(mtx);
            primes.push_back(i);
        }
    }
}

int main() 
{
    const int rangeStart = 0;
    const int rangeEnd = 200;
    const int numThreads = 5;

    int step = (rangeEnd - rangeStart + 1) / numThreads;
    int start = rangeStart;
    int end = start + step - 1;

    vector<thread> threads;
    for (int i = 0; i < numThreads; ++i) 
    {
        threads.emplace_back(find_primes, start, end);
        start = end + 1;
        if (i == numThreads - 2) {end = rangeEnd;}
        else {end = end + step;}
    }
    for (auto &thread : threads) {
        thread.join();
    }
    cout << "[" << rangeStart << ", " << rangeEnd << "] 范围中的所有素数: " << endl;
    for (int prime : primes) 
    {
        cout << prime << " ";
    }
    cout << endl;
    return 0;
}
