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
    condition_variable cv; // 条件变量，用于等待线程完成  
    int numThreads = thread::hardware_concurrency(); // 获取CPU核心数，作为线程数  
    vector<thread> threads(numThreads); // 创建线程数组  
    int chunkSize = (end - start + 1) / numThreads; // 计算每个线程处理的数据量  
  
    // 启动线程，每个线程处理一部分数据  
    for (int i = 0; i < numThreads; i++) {  
        int start1 = start + i * chunkSize;  
        int end1 = start + (i + 1) * chunkSize - 1;  
        if (i == numThreads - 1) {  
            end1 = end; // 最后一个线程处理剩余的数据  
        }  
        threads[i] = thread([start1, end1, &primes, &mtx, &cv]() {  
            vector<int> localPrimes; // 每个线程使用的局部素数容器  
            findPrimes(start1, end1, localPrimes); // 在每个线程中找出素数并存入局部容器  
            mtx.lock(); // 获取互斥锁，保证同一时刻只有一个线程能修改全局素数容器  
            primes.insert(primes.end(), localPrimes.begin(), localPrimes.end()); // 将局部容器中的素数添加到全局容器中  
            mtx.unlock(); // 释放互斥锁，允许其他线程修改全局容器  
            cv.notify_one(); // 通知等待的线程，该线程已完成工作  
        });  
    }  
  
    // 等待所有线程完成工作  
    unique_lock<mutex> ul(mtx); // 获取互斥锁，等待所有线程完成工作后释放锁并通知其他线程  
    cv.wait(ul, []{ return primes.size() == end - start + 1; }); // 等待所有素数都添加到全局容器中后继续执行后面的代码  
    ul.unlock(); // 释放互斥锁，允许其他线程修改全局容器中的数据或创建新的线程等操作  
  
    // 输出结果，每个线程打印各自处理的范围内的素数即可。此处为示例，仅输出总和。  
    cout << "Total prime numbers: " << primes.size() << endl; // 输出总素数个数（包括重复的）  
    cout << "Sum of prime numbers: " << accumulate(primes.begin(), primes.end(), 0) << endl; // 输出所有素数的和（包括重复的）  
  
    // 等待所有线程结束，然后退出程序。这一步是为了保证在程序退出前，所有线程都已完成工作。  
    for (auto& th : threads) {  
        th.join(); // 等待所有线程结束后再退出程序  
    }  
    return 0;  
}
