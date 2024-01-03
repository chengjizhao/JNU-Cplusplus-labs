#include <iostream>  
#include <vector>  
#include <thread>  
#include <mutex>  
  
const int MAX_NUM = 100000; // 最大的数，可以根据需要调整  
const int NUM_THREADS = std::thread::hardware_concurrency(); // 使用可用的硬件线程数  
  
std::vector<bool> isPrime(MAX_NUM + 1, true); // 标记数组，默认所有数为素数  
std::mutex mtx; // 全局互斥锁，用于保护共享数据  
  
// 函数用于检查一个数是否为素数  
void checkPrime(int start, int end) 
{  
    for (int i = start; i <= end; ++i) 
    {  
        if (i <= 1) continue; // 小于等于1的数不是素数  
        if (i % 2 == 0) continue; // 除了2之外，所有偶数都不是素数  
        for (int j = 3; j * j <= i; j += 2) 
        { // 从3开始，步长为2，因为所有的素数都是奇数  
            std::lock_guard<std::mutex> lock(mtx); // 在作用域内自动锁定和解锁互斥锁  
            if (i % j == 0) 
            { // 如果i能被j整除，那么i不是素数  
                isPrime[i] = false;  
                break; // 跳出内层循环，继续检查下一个数  
            }  
        }  
    }  
}  
  
int main() 
{  
    // 将检查素数的任务分配给多个线程执行  
    std::vector<std::thread> threads;  
    int chunkSize = MAX_NUM / NUM_THREADS; // 每个线程检查的数的范围  
    for (int i = 0; i < NUM_THREADS; ++i) 
    {  
        int start = i * chunkSize;  
        int end = (i == NUM_THREADS - 1) ? MAX_NUM : start + chunkSize - 1;  
        threads.push_back(std::thread(checkPrime, start, end)); // 启动新线程  
    }  
    // 等待所有线程完成  
    for (auto& t : threads) 
    {  
        t.join();  
    }  
    // 输出所有的素数  
    for (int i = 2; i <= MAX_NUM; ++i) 
    {  
        if (isPrime[i]) 
        { // 如果该数是素数，则输出该数  
            std::cout << i << " ";  
        }  
    }  
    std::cout << std::endl;  
    return 0;  
}