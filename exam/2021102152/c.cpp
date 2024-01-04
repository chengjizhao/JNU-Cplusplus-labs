#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <chrono>
std::mutex mtx;
std::condition_variable cv;
int random_num = 0; // 共享数据结构，保存随机数和平方根
// 生成随机数的函数
void generate_random(int seed) {
    std::mt19937 gen(seed); // 使用当前时间作为种子
    std::uniform_int_distribution<> distr(-1000, 1000); // 生成-1000到1000之间的随机数
    for (int i = 0; i < 10; ++i) { // 生成10个随机数
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 休眠1秒以模拟计算时间
        random_num = distr(gen); // 生成随机数并保存到共享数据结构中
    }
}
// 计算平方根的函数
void calculate_square_root() 
{
    std::unique_lock<std::mutex> lock(mtx); // 锁定互斥量
    cv.wait(lock, []{ return random_num != 0; }); // 等待随机数生成完毕
    double square_root = std::sqrt(random_num); // 计算平方根并保存到共享数据结构中
    lock.unlock(); // 解锁互斥量
    cv.notify_one(); // 通知计算线程计算完成
    std::cout << "Random number: " << random_num << ", Square root: " << square_root << std::endl; // 输出结果
}
int main() {
    std::thread t1(generate_random, std::chrono::system_clock::now().time_since_epoch().count()); // 创建生成随机数的线程
    std::thread t2(calculate_square_root); // 创建计算平方根的线程
    t1.join(); // 等待生成随机数的线程完成
    t2.join(); // 等待计算平方根的线程完成
    return 0;
}