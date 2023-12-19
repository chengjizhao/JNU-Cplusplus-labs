#include <iostream>  
#include <vector>  
#include <thread>  
#include <mutex>  
#include <condition_variable>  
  
using namespace std;  
  
// 判断一个数是否为素数  
bool isPrime(int num) {  
    if (num <= 1) {  
        return false;  
    }  
    for (int i = 2; i * i <= num; i++) {  
        if (num % i == 0) {  
            return false;  
        }  
    }  
    return true;  
}  
  
// 找出给定范围内所有素数  
void findPrimes(int start, int end, vector<int>& primes) {  
    for (int i = start; i <= end; i++) {  
        if (isPrime(i)) {  
            primes.push_back(i);  
        }  
    }  
}  
  
int main() {  
    int start, end;  
    cout << "Enter start and end of range: ";  
    cin >> start >> end;  
  
    vector<int> primes;  
    mutex mtx; // 互斥锁，保证线程安全  
    condition_variable cv;   
    int numThreads = thread::hardware_concurrency();   
    vector<thread> threads(numThreads);   
    int chunkSize = (end - start + 1) / numThreads;   
  
    // 启动线程，每个线程处理一部分数据  
    for (int i = 0; i < numThreads; i++) {  
        int start1 = start + i * chunkSize;  
        int end1 = start + (i + 1) * chunkSize - 1;  
        if (i == numThreads - 1) {  
            end1 = end; // 最后一个线程处理剩余的数据  
        }  
        threads[i] = thread([start1, end1, &primes, &mtx, &cv]() {  
            vector<int> localPrimes;   
            findPrimes(start1, end1, localPrimes);   
            mtx.lock();   
            primes.insert(primes.end(), localPrimes.begin(), localPrimes.end()); 
            mtx.unlock();   
            cv.notify_one();   
        });  
    }  
  
    // 等待所有线程完成工作  
    unique_lock<mutex> ul(mtx); 
    cv.wait(ul, []{ return primes.size() == end - start + 1; }); 
    ul.unlock(); 
  
    // 输出总和
    cout << "Sum of prime numbers: " << accumulate(primes.begin(), primes.end(), 0) << endl; 
    // 等待所有线程结束，然后退出程序。
    for (auto& th : threads) {  
        th.join();   
    }  
    return 0;  
}