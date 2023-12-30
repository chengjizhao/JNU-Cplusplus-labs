#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void findPrimes(int start, int end, vector<int>& result, mutex& mtx)
{
    for (int i = start; i <= end; i++)
    {
        if (isPrime(i))
        {
            lock_guard<mutex> lock(mtx);
            result.push_back(i);
        }
    }
}

int main()
{
    const int numThreads = 5;
    const int range = 1000;
    vector<int> primes;
    vector<thread> threads;
    mutex mtx;

    int step = range / numThreads;
    for (int i = 0; i < numThreads; i++)
    {
        //确定一个线程的素数处理量
        int start = i * step + 1;
        int end = (i == numThreads - 1) ? range : (i + 1) * step;
        //thread(findPrimes, start, end, ref(primes), ref(mtx))，后面的start等是findPrimes的参数
        threads.push_back(thread(findPrimes, start, end, ref(primes), ref(mtx)));
    }

    for (auto& t : threads)
    {
        t.join();
    }

    cout << "Prime numbers from 0 to 1000: ";
    for (int prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
