#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cmath>
#include <random>

struct Result {
    double randomNumber; //存储生成的随机数
    double squareRoot;//存储随机数的平方根
};

std::mutex mtx;
std::condition_variable cv;//条件变量，确保线程同步
bool ready = false;//表示随机数是否已经生成
Result result;//存储生成的平方根和随机数

void generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 10.0);

    std::unique_lock<std::mutex> lock(mtx);
    result.randomNumber = dis(gen);
    ready = true;
    cv.notify_one();
}

void calculateSquareRoot() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });
    result.squareRoot = std::sqrt(result.randomNumber);
}

int main() {
    std::thread t1(generateRandomNumber);
    std::thread t2(calculateSquareRoot);

    t1.join();
    t2.join();

    std::cout << "Random number: " << result.randomNumber << std::endl;
    std::cout << "Square root: " << result.squareRoot << std::endl;

    return 0;
}