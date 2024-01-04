#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <cmath>

std::mutex mtx;
std::condition_variable cv;
bool isReady = false;
int randomNumber =0;
double squareRoot =0.0;

struct Result {
 int number;
 double squareRoot;
};

void generateRandomNumber(Result& result) {
 std::random_device rd;
 std::mt19937 gen(rd());
 std::uniform_int_distribution<> dis(1,1000000);

 std::unique_lock<std::mutex> lock(mtx);
 result.number = dis(gen);
 isReady = true;
 lock.unlock();

 cv.notify_one();
}

void calculateSquare(Result& result) {
 std::unique_lock<std::mutex> lock(mtx);
 cv.wait(lock, [] { return isReady; });

 result.squareRoot = std::sqrt(result.number);
}

int main() {
 Result result;

 std::thread t1(generateRandomNumber, std::ref(result));
 std::thread t2(calculateSquare, std::ref(result));

 t1.join();
 t2.join();

 std::cout << "Random number: " << result.number << std::endl;
 std::cout << "Square root: " << result.squareRoot << std::endl;

 return 0;
}
