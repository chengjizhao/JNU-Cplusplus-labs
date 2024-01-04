#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int counter = 0;

void incrementCounter() {
    for (int i = 0; i < 100; ++i) {
        mtx.lock();
        counter++;
        mtx.unlock();
    }
}

void decrementCounter() {
    for (int i = 0; i < 50; ++i) {
        mtx.lock();
        counter--;
        mtx.unlock();
    }
}

int main() {
    std::thread t1(incrementCounter);
    std::thread t2(decrementCounter);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}