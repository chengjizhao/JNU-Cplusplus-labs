#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cmath>
#include <random>
#include <chrono>

// �ṹ�����ڱ�����
struct Result {
    double randomNumber;
    double squareRoot;
};

std::mutex mtx;
std::condition_variable cv;
bool dataReady = false;
Result sharedResult;

void generateRandomNumber() {
    // ���������
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 100.0);

    {
        std::lock_guard<std::mutex> lock(mtx);
        sharedResult.randomNumber = dis(gen);
        dataReady = true;
    }

    // ֪ͨ�����߳̿��Կ�ʼִ��
    cv.notify_one();
}

void calculateSquareRoot() {
    std::unique_lock<std::mutex> lock(mtx);

    // �ȴ������߳����
    cv.wait(lock, []{ return dataReady; });

    // ����ƽ����
    sharedResult.squareRoot = std::sqrt(sharedResult.randomNumber);
}

int main() {
    std::thread generator(generateRandomNumber);
    std::thread calculator(calculateSquareRoot);

    // �ȴ��߳����
    generator.join();
    calculator.join();

    // ������
    std::cout << "Random Number: " << sharedResult.randomNumber << std::endl;
    std::cout << "Square Root: " << sharedResult.squareRoot << std::endl;

    // �ȴ��û����룬��ֹ���������˳�
    std::cout << "Press Enter to exit." << std::endl;
    std::cin.get();

    return 0;
}