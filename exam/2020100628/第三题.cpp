#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <vector>

class ThreadPool {
public:
    explicit ThreadPool(size_t numThreads)
        : stop(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            threads.emplace_back([this] {
                while (true) {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        condition.wait(lock, [this] { return stop || !taskQueue.empty(); });

                        if (stop && taskQueue.empty()) {
                            return;
                        }

                        task = std::move(taskQueue.front());
                        taskQueue.pop();
                    }

                    task();
                }
            });
        }
    }

    template<class F>
    void enqueue(F&& task) {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            taskQueue.emplace(std::forward<F>(task));
        }
        condition.notify_one();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }

        condition.notify_all();

        for (std::thread& worker : threads) {
            worker.join();
        }
    }

private:
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> taskQueue;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
};

int main() {
    ThreadPool threadPool(2);  

    
    for (int i = 0; i < 5; ++i) {
        threadPool.enqueue([i] {
            std::cout << "Task " << i << " executed by thread " << std::this_thread::get_id() << std::endl;
        });
    }

    
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}
