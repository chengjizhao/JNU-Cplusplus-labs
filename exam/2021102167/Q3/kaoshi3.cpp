#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cmath>
#include <random>

struct Result {
    double randomNumber; //�洢���ɵ������
    double squareRoot;//�洢�������ƽ����
};

std::mutex mtx;
std::condition_variable cv;//����������ȷ���߳�ͬ��
bool ready = false;//��ʾ������Ƿ��Ѿ�����
Result result;//�洢���ɵ�ƽ�����������

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