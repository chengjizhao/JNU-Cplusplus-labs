#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <cmath>

struct SharedData {
    int random_number;
    double sqrt_result;
};
SharedData shared_data;
std::mutex mtx;
std::condition_variable cv;

void generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    std::unique_lock<std::mutex> lock(mtx);
    shared_data.random_number = dis(gen);
    std::cout << "生成的随机数为: " << shared_data.random_number << std::endl;
    lock.unlock();
    cv.notify_one();
}


void calculateSquareRoot() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return shared_data.random_number != 0; });  
    shared_data.sqrt_result = std::sqrt(shared_data.random_number);
    std::cout << "随机数的平方根为: " << shared_data.sqrt_result << std::endl;
}

int main() {
    std::thread generateThread(generateRandomNumber);
    std::thread calculateThread(calculateSquareRoot);

    generateThread.join();
    calculateThread.join();

    std::cout << "最终结果:" << std::endl;
    std::cout << "随机数: " << shared_data.random_number << std::endl;
    std::cout << "平方根: " << shared_data.sqrt_result << std::endl;

    return 0;
}



