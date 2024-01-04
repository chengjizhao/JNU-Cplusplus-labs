#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <random>
using namespace std;

mutex mtx;
condition_variable notFull, notEmpty;
queue<int> dataQueue;

const int MAX_SIZE = 20;

// 生产者线程
void producer() {
    while (true) 
    {
        unique_lock<mutex> lock(mtx);
        notFull.wait(lock, [] { return dataQueue.size() < MAX_SIZE; });
        for (int i = 0; i < 3; ++i) 
        {
            int data = rand() % 100;
            dataQueue.push(data);
            std::cout << "Produced: " << data << std::endl;
        }

        lock.unlock();
        notEmpty.notify_all();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

// 消费者线程
void consumer(int id) {
    while (true) 
    {
        unique_lock<std::mutex> lock(mtx);
        notEmpty.wait(lock, [] { return !dataQueue.empty(); });
        int data = dataQueue.front();
        dataQueue.pop();
        cout << "Consumer " << id << " consumed: " << data << endl;
        lock.unlock();
        notFull.notify_all();  
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    thread producerThread(producer);

    thread consumerThread1(consumer, 1);
    thread consumerThread2(consumer, 2);
    thread consumerThread3(consumer, 3);
    thread consumerThread4(consumer, 4);

    producerThread.join();
    consumerThread1.join();
    consumerThread2.join();
    consumerThread3.join();
    consumerThread4.join();

    return 0;
}
