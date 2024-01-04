#include <iostream>  
#include <thread>  
#include <mutex>  
#include <condition_variable>  
#include <cmath>  
#include <random>  
#include <chrono>  
  
// 共享数据结构  
struct SharedData {  
    double number;  
    double squareRoot;  
    bool numberGenerated;  
    std::mutex mtx;  
    std::condition_variable cv;  
};  
  
// 生成随机数的线程函数  
void generateRandomNumber(SharedData& data) {  
    std::random_device rd; // 用于获取随机数种子的设备  
    std::mt19937 gen(rd()); // 以 rd() 为种子初始化 Mersenne Twister 生成器  
    std::uniform_real_distribution<> dis(1.0, 100.0); // 在 [1.0, 100.0] 之间的均匀分布  
  
    {  
        std::unique_lock<std::mutex> lock(data.mtx);  
        data.number = dis(gen); // 生成随机数并存储到共享数据结构中  
        data.numberGenerated = true; // 标记随机数已生成  
        lock.unlock(); // 解锁，允许其他线程访问共享数据  
    }  
    data.cv.notify_one(); // 通知等待的线程（计算线程）  
}  
  
// 计算平方根的线程函数  
void calculateSquareRoot(SharedData& data) {  
    std::unique_lock<std::mutex> lock(data.mtx);  
    while (!data.numberGenerated) { // 如果随机数还未生成，则等待  
        data.cv.wait(lock); // 等待通知，同时释放锁，以便其他线程可以修改条件  
        // 当被通知时，会重新获取锁并继续执行  
    }  
    data.squareRoot = std::sqrt(data.number); // 计算平方根并存储到共享数据结构中  
    lock.unlock(); // 解锁，允许其他线程访问共享数据（如果需要的话）  
}  
  
int main() {  
    SharedData data; // 创建共享数据结构实例  
    std::thread t1(generateRandomNumber, std::ref(data)); // 创建生成随机数的线程  
    std::thread t2(calculateSquareRoot, std::ref(data)); // 创建计算平方根的线程  
  
    t1.join(); // 等待生成随机数的线程结束  
    t2.join(); // 等待计算平方根的线程结束  
  
    // 输出最终的随机数和其平方根（这里不需要再次加锁，因为两个线程已经执行完毕）  
    std::cout << "Random number: " << data.number << std::endl;  
    std::cout << "Square root: " << data.squareRoot << std::endl;  
  
    return 0;  
}