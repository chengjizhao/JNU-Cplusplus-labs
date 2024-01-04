#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <random>

class ThreadSafeQueue 
{
private:
    std::queue<int> q;
    std::mutex mtx;
    std::condition_variable notFull, notEmpty;
    const int maxSize = 20;

    public:
    void produce() 
    {
        while (true) 
        {
            std::unique_lock<std::mutex> lock(mtx);
            notFull.wait(lock, [this] {
                 return q.size() < maxSize; 
                 });

            for (int i = 0; i < 3; ++i) 
            {
                int data = rand() % 100; 
                q.push(data);
                std::cout << "Produced: " << data << std::endl;
            }

            notEmpty.notify_all();
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(1)); 
        }
    }

    void consume(int id) 
    {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            notEmpty.wait(lock, [this] { 
                return !q.empty(); 
                });

            int data = q.front();
            q.pop();
            std::cout << "Consumer " << id << " consumed: " << data << std::endl;

            lock.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(rand() % 2 + 1)); // Consumer waits 1 or 2 seconds
            notFull.notify_all();
        }
    }
};

int main() 
{
    ThreadSafeQueue queue;
    std::thread producer(&ThreadSafeQueue::produce, &queue);

    std::thread consumers[4];
    for (int i = 0; i < 4; ++i) 
    {
        consumers[i] = std::thread(&ThreadSafeQueue::consume, &queue, i + 1);
    }

    producer.join();
    for (int i = 0; i < 4; ++i) 
    {
        consumers[i].join();
    }

    return 0;
}