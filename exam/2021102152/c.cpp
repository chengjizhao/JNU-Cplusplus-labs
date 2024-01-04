#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <chrono>
std::mutex mtx;
std::condition_variable cv;
int random_num = 0; 
// 生成随机数的函数
void generate_random(int seed) {
    std::mt19937 gen(seed); //
    std::uniform_int_distribution<> distr(-1000, 1000); 
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); 
        random_num = distr(gen); 
    }
}
// 计算平方根的函数
void calculate_square_root() 
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return random_num != 0; }); 
    double square_root = std::sqrt(random_num); 
    lock.unlock(); 
    cv.notify_one();
    std::cout << "Random number: " << random_num << ", Square root: " << square_root << std::endl; 
}
int main() {
    std::thread t1(generate_random, std::chrono::system_clock::now().time_since_epoch().count()); 
    std::thread t2(calculate_square_root); 
    t1.join();
    t2.join();
    return 0;
}
