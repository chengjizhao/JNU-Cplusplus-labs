#include <iostream>
#include <thread> 
#include <queue> 
#include <condition_variable> 
#include <mutex>
using namespace std;

// 队列，最大长度为20
queue<int> dataQueue;
condition_variable cv; 
mutex mtx; 
const int maxLength = 20;

// 生产者
void producer() {
    for(int i = 1; i <= 60; i++) { // 生产60个数据
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []() {return dataQueue.size()<maxLength;}); // 队列未满则可以生产

        dataQueue.push(i);
        cout << "Produced: " << i << endl;

        lock.unlock();
        cv.notify_all(); // 唤醒等待的线程
    }
}

// 消费者
void consumer() {
    while(true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []() {return !dataQueue.empty();}); // 队列非空则可以消费

        cout << "Consumed: " << dataQueue.front() << endl;
        dataQueue.pop();

        lock.unlock();
        cv.notify_all(); // 唤醒等待的线程
    }
}

int main() {
    thread producerThread(producer);
    thread consumerThreads[4];

    for (int i = 0; i < 4; i++) {
        consumerThreads[i] = thread(consumer);
    }

    producerThread.join();
    for (int i = 0; i < 4; i++) {
        consumerThreads[i].join();
    }

    return 0;
}
