#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cmath>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;
double randomNumber;
double result;

void generateRandomNumber()
{
    unique_lock<mutex> lock(mtx);

    // 模拟生成随机数
    srand(time(0));
    randomNumber = rand() % 100;
    cout << "随机生成的数是: " << randomNumber << endl;

    ready = true;
    cv.notify_one();
}

void calculateSquareRoot() {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });

    result = sqrt(randomNumber);
    cout << "这个数的均方根是: " << result << endl;
}

int main() {
    std::thread t1(generateRandomNumber);
    std::thread t2(calculateSquareRoot);

    t1.join();
    t2.join();

    return 0;
}