#include <cmath>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>

class RandomNumberHandler {
 public:
  RandomNumberHandler() : ready(false), number(0.0), squareRoot(0.0) {}

  void generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(1.0, 10.0);
    std::unique_lock<std::mutex> lock(mutex);
    number = dis(gen);
    ready = true;
    std::cout << "Generated random number: " << number << std::endl;
    cond.notify_one();
  }

  void calculateSquareRoot() {
    std::unique_lock<std::mutex> lock(mutex);
    cond.wait(lock, [this] { return ready; });
    squareRoot = std::sqrt(number);
    std::cout << "Square root of " << number << " is: " << squareRoot
              << std::endl;
  }

 private:
  bool ready;
  double number;
  double squareRoot;
  std::mutex mutex;
  std::condition_variable cond;
};

int main() {
  RandomNumberHandler handler;
  std::thread t1(&RandomNumberHandler::generateRandomNumber, &handler);
  std::thread t2(&RandomNumberHandler::calculateSquareRoot, &handler);

  t1.join();
  t2.join();

  return 0;
}