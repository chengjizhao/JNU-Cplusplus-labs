#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

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

void find_primes(int start, int end, vector<int>& primes) {
    for (int i = start; i <= end; ++i) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
    }
}

void thread_function(int start, int end, vector<int>& primes) {
    find_primes(start, end, primes);
}

int main() {
    int n;
    cout << "请输入范围：";
    cin >> n;

    vector<int> primes;
    clock_t start = clock();

    vector<thread> threads;
    for (int i = 1; i <= n; i += n) {
        threads.emplace_back(thread_function, i, i + n-1, ref(primes));
    }

    for (thread& t : threads) {
        t.join();
    }

    cout << "找到的素数有：" << endl;
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    clock_t end = clock();
    cout << "耗时：" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;

    return 0;
}