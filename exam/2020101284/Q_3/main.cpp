#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex countMutex;
int counter = 0;

// 递增计数器的函数
void incrementCounter() {
    for (int i = 0; i < 100; i++) {
        countMutex.lock();
        counter++;
        countMutex.unlock();
    }
}

// 递减计数器的函数
void decrementCounter() {
    for (int i = 0; i < 50; i++) {
        countMutex.lock();
        counter--;
        countMutex.unlock();
    }
}

int main() {
    thread t1(incrementCounter);
    thread t2(decrementCounter);

    t1.join();
    t2.join();

    cout << "Final counter value: " << counter << endl;

    return 0;
}
