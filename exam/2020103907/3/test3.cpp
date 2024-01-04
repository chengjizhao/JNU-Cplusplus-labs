#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <random>

using namespace std;
mutex mtx;
condition_variable not_full, not_empty;
queue<int> data_queue;
const int max_queue_size = 20;

void producer() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        not_full.wait(lock, [] { return data_queue.size() < max_queue_size; });

        for (int i = 0; i < 3; ++i) {
            int data = rand() % 100;  // 生成随机数据
            data_queue.push(data);
            cout << "Produced: " << data << endl;
        }

        lock.unlock();
        not_empty.notify_all();

        this_thread::sleep_for(chrono::seconds(1));  // 每秒生产3个数据
    }
}

void consumer(int id) {
    while (true) {
        unique_lock<mutex> lock(mtx);
        not_empty.wait(lock, [] { return !data_queue.empty(); });

        int data = data_queue.front();
        data_queue.pop();
        cout << "Consumer " << id << " Consumed: " << data << endl;

        lock.unlock();
        not_full.notify_all();

        int wait_time = (rand() % 2) + 1;
        this_thread::sleep_for(chrono::seconds(wait_time));
    }
}

int main() {
    thread producer_thread(producer);
    thread consumer_thread1(consumer, 1);
    thread consumer_thread2(consumer, 2);
    thread consumer_thread3(consumer, 3);
    thread consumer_thread4(consumer, 4);

    producer_thread.join();
    consumer_thread1.join();
    consumer_thread2.join();
    consumer_thread3.join();
    consumer_thread4.join();

    return 0;
}
