#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

class ThreadPool {
public:
    ThreadPool(size_t numThreads) : stop(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    function<void()> task;

                    {
                        unique_lock<mutex> lock(queueMutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });

                        if (stop && tasks.empty()) {
                            return;
                        }

                        task = move(tasks.front());
                        tasks.pop();
                    }

                    task();
                }
            });
        }
    }

    template<class F>
    void enqueue(F&& f) {
        {
            unique_lock<mutex> lock(queueMutex);
            tasks.emplace(forward<F>(f));
        }

        condition.notify_one();
    }

    ~ThreadPool() {
        {
            unique_lock<mutex> lock(queueMutex);
            stop = true;
        }

        condition.notify_all();

        for (thread& worker : workers) {
            worker.join();
        }
    }

private:
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex queueMutex;
    condition_variable condition;
    bool stop;
};

int main() {
    // 创建线程池，包含3个工作线程
    ThreadPool pool(3);

    // 提交任务给线程池
    for (int i = 1; i <= 5; ++i) {
        pool.enqueue([i] {
            cout << "Task " << i << " executed by Thread " << this_thread::get_id() << endl;
        });
    }

    // 等待任务完成
    this_thread::sleep_for(chrono::seconds(2));

    return 0;
}