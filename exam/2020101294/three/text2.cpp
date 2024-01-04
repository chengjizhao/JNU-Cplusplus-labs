#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cmath>
#include <random>
#include <chrono>

// 结构体用于保存结果
struct Result {
    double randomNumber;
    double squareRoot;
};

std::mutex mtx;
std::condition_variable cv;
bool dataReady = false;
Result sharedResult;

void generateRandomNumber() {
    // 生成随机数
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 100.0);

    {
        std::lock_guard<std::mutex> lock(mtx);
        sharedResult.randomNumber = dis(gen);
        dataReady = true;
    }

    // 通知计算线程可以开始执行
    cv.notify_one();
}

void calculateSquareRoot() {
    std::unique_lock<std::mutex> lock(mtx);

    // 等待生成线程完成
    cv.wait(lock, []{ return dataReady; });

    // 计算平方根
    sharedResult.squareRoot = std::sqrt(sharedResult.randomNumber);
}

int main() {
    std::thread generator(generateRandomNumber);
    std::thread calculator(calculateSquareRoot);

    // 等待线程完成
    generator.join();
    calculator.join();

    // 输出结果
    std::cout << "Random Number: " << sharedResult.randomNumber << std::endl;
    std::cout << "Square Root: " << sharedResult.squareRoot << std::endl;

    // 等待用户输入，防止程序立即退出
    std::cout << "Press Enter to exit." << std::endl;
    std::cin.get();

    return 0;
}