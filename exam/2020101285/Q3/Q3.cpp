#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cmath>
#include <random>

// 共享数据结构
struct SharedData {
    double randomNumber;
    double squareRoot;
    bool generated;

    SharedData() : randomNumber(0.0), squareRoot(0.0), generated(false) {}
};

std::mutex mtx;
std::condition_variable cv;
SharedData sharedData;

// 生成随机数的线程函数
void generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(1.0, 100.0);

    {
        std::unique_lock<std::mutex> lock(mtx);
        sharedData.randomNumber = dis(gen);
        sharedData.generated = true;
        cv.notify_one(); // 通知等待的线程
    }

    std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟其他计算
}

// 计算平方根的线程函数
void calculateSquareRoot() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return sharedData.generated; });

    sharedData.squareRoot = std::sqrt(sharedData.randomNumber);
}

int main() {
    std::thread thread1(generateRandomNumber);
    std::thread thread2(calculateSquareRoot);

    thread1.join();
    thread2.join();

    std::cout << "Random Number: " << sharedData.randomNumber << std::endl;
    std::cout << "Square Root: " << sharedData.squareRoot << std::endl;

    return 0;
}
