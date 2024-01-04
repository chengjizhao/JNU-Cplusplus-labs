#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>

class ThreadPool {
public:
    ThreadPool(size_t num_threads);
    ~ThreadPool();

    void enqueue(std::function<void()> task);
    std::queue<std::function<void()>> task_queue;
private:

    std::vector<std::thread> worker_threads;
    std::mutex queue_mutex;
    std::condition_variable condition;
    std::atomic<bool> stop;

    void worker_thread();
};

ThreadPool::ThreadPool(size_t num_threads) : stop(false) {
    for (size_t i = 0; i < num_threads; ++i) {
        worker_threads.emplace_back(&ThreadPool::worker_thread, this);
    }
}

ThreadPool::~ThreadPool() {
    stop = true;
    condition.notify_all();
    for (auto &thread : worker_threads) {
        thread.join();
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        task_queue.push(task);
    }
    condition.notify_one();
}

void ThreadPool::worker_thread() {
    while (!stop) {
        std::function<void()> task;

        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            condition.wait(lock, [this] { return !task_queue.empty() || stop; });

            if (stop) {
                break;
            }

            task = task_queue.front();
            task_queue.pop();
        }

        task();
    }
}

int main() {
    ThreadPool thread_pool(4);

    std::function<void()> task1 = []() {
        std::cout << "Task 1 executed." << std::endl;
    };

    std::function<void()> task2 = []() {
        std::cout << "Task 2 executed." << std::endl;
    };

    std::function<void()> task3 = []() {
        std::cout << "Task 3 executed." << std::endl;
    };

    thread_pool.enqueue(task1);
    thread_pool.enqueue(task2);
    thread_pool.enqueue(task3);

    while (!thread_pool.task_queue.empty()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}