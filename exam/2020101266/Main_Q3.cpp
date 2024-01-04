#include <iostream>
#include <thread>
#include <mutex>

class Counter {
private:
    int count;
    std::mutex mtx;

public:
    Counter() : count(0) {}

    void increment(int n) {
        std::lock_guard<std::mutex> lock(mtx);
        for (int i = 0; i < n; ++i) {
            count++;
        }
    }

    void decrement(int n) {
        std::lock_guard<std::mutex> lock(mtx);
        for (int i = 0; i < n; ++i) {
            count--;
        }
    }

    int getCount() const {
        return count;
    }
};

int main() {
    Counter counter;

    std::thread incrementThread([&counter]() {
        counter.increment(100);
        });

    std::thread decrementThread([&counter]() {
        counter.decrement(50);
        });

    incrementThread.join();
    decrementThread.join();

    std::cout << "Final count: " << counter.getCount() << std::endl;

    return 0;
}
