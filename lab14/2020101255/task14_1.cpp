#include<iostream>
#include<vector>
#include<thread>
#include<mutex>

using namespace std;

mutex g_mutex;
vector<int> g_primeNumbers;

bool isPrime(int number)
{
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

void findPrimes(int start, int end)
{
    vector<int> primes;
    for (int i = start; i <= end; ++i)
    {
        if (isPrime(i))
            primes.push_back(i);
    }

    lock_guard<mutex> lock(g_mutex);
    g_primeNumbers.insert(g_primeNumbers.end(), primes.begin(), primes.end());
}

int main()
{
    const int numThreads = 4;
    const int start = 1;
    const int end = 100;

    vector<thread> threads;
    const int range = (end - start + 1) / numThreads;
    int threadStart = start;
    int threadEnd = threadStart + range - 1;

    for (int i = 0; i < numThreads; ++i)
    {
        if (i == numThreads - 1)
            threadEnd = end;

        threads.emplace_back(findPrimes, threadStart, threadEnd);

        threadStart += range;
        threadEnd += range;
    }

    for (thread& t : threads)
        t.join();

    for (const int prime : g_primeNumbers)
        cout << prime << " ";

    return 0;
}
