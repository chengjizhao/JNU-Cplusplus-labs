// 引入必要的头文件。iostream用于输入输出流，vector用于动态数组，thread用于多线程，mutex用于互斥量。  
#include <iostream>  
#include <vector>  
#include <thread>  
#include <mutex>  
using namespace std;  
  
// 声明一个全局的互斥量mtx，用于保护共享资源，防止多个线程同时访问和修改数据。  
mutex mtx;  
// 声明一个整数向量primes，用于存储素数。  
vector<int> primes;  
  
// 定义一个函数Prime(int n)，用于判断一个整数n是否为素数。  
int Prime(int n)   
{  
    // 如果n小于等于1，直接返回0，表示n不是素数。  
    if (n <= 1)  
        return 0;  
    // 从2循环到sqrt(n)，检查n是否可被整除。如果可被整除，返回0；否则继续循环。  
    for (int i = 2; i * i <= n; ++i) {  
        if (n % i == 0)  
            return 0;  
    }  
    // 如果循环结束都没有找到能整除n的数，则返回1，表示n是素数。  
    return 1;  
}  
  
// 定义一个函数find_primes(int start, int end)，用于查找指定范围内的素数。  
void find_primes(int start, int end)   
{  
    // 从start循环到end，检查每个数是否是素数。如果是素数，则使用互斥量mtx保护对primes向量的访问，并将该数添加到primes向量中。  
    for (int i = start; i <= end; ++i) {  
        if (Prime(i) == 1)   
        {  
            lock_guard<mutex> lock(mtx);  // 使用lock_guard智能锁自动管理mtx的锁定和解锁。  
            primes.push_back(i);  // 将素数i添加到primes向量中。  
        }  
    }  
}  
  
// 主函数main()开始。  
int main()   
{  
    // 定义常量rangeStart和rangeEnd，分别表示查找范围的起始和结束值。这里查找的是[0,200]范围内的素数。  
    const int rangeStart = 0;  
    const int rangeEnd = 200;  
    // 定义常量numThreads，表示使用的线程数量。这里使用5个线程进行查找。  
    const int numThreads = 5;  
  
    // 计算每个线程应该查找的范围。由于有5个线程，所以每个线程查找[rangeStart, rangeEnd]范围内的一个五分之一的子范围。  
    int step = (rangeEnd - rangeStart + 1) / numThreads;  
    // 初始化线程起始和结束范围。第一个线程从rangeStart开始，最后一个线程到rangeEnd结束。其他线程在中间平均分配剩余的范围。  
    int start = rangeStart;  
    int end = start + step - 1;  
  
    // 创建一个空的线程向量threads，用于存储启动的线程。  
    vector<thread> threads;  
    // 使用for循环启动numThreads个线程，每个线程调用find_primes函数并传入相应的范围参数。然后将线程对象添加到threads向量中。  
    for (int i = 0; i < numThreads; ++i)   
    {  
        threads.emplace_back(find_primes, start, end);  // 启动线程并存储线程对象。  
        start = end + 1;  // 更新线程起始范围为下一个位置。  
        if (i == numThreads - 2) {end = rangeEnd;}  // 如果这是倒数第二个线程，则将end设置为rangeEnd，使其处理剩余的范围。  
        else {end = end + step;}  // 其他线程继续查找下一个范围。  
    }  
    // 使用for循环等待所有线程完成其工作。这是通过调用每个线程对象的join方法实现的，这将阻塞主线程直到相应线程完成执行。  
    for (auto &thread : threads) {  
        thread.join();  // 等待线程完成执行。  
    }  
    // 输出找到的所有素数。这是通过遍历primes向量并打印每个素数实现的。最后打印一个换行符以保持输出整洁。  
    cout << "[" << rangeStart << ", " << rangeEnd << "] 范围中的所有素数: " << endl;  // 输出查找范围的提示信息。  
    for (int prime : primes) 
    {
        cout << prime << " ";
    }
    cout << endl;
    return 0;
}