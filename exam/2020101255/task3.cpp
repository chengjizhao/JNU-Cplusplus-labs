#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class ThreadPool
{
    public:
        ThreadPool(size_t numThreads) : stop(false)
        {
            for (size_t i = 0; i < numThreads; ++i)
            {
                threads.emplace_back([this] {
                    while (true)
                    {
                        function<void()> task;
                        {
                            unique_lock<mutex> lock(queueMutex);
                            condition.wait(lock, [this] { return stop || !tasks.empty(); });
                            if (stop && tasks.empty())
                                return;
                            task = move(tasks.front());
                            tasks.pop();
                        }
                        task();
                    }
                });
            }
        }

        template <class F, class... Args>
        void enqueue(F&& f, Args&&... args)
        {
            {
                unique_lock<mutex> lock(queueMutex);
                tasks.emplace(bind(forward<F>(f), forward<Args>(args)...));
            }
            condition.notify_one();
        }

        ~ThreadPool()
        {
            {
                unique_lock<mutex> lock(queueMutex);
                stop = true;
            }
            condition.notify_all();
            for (auto& thread : threads)
                thread.join();
        }

    private:
        vector<thread> threads;
        queue<function<void()>> tasks;
        mutex queueMutex;
        condition_variable condition;
        bool stop;
};

int main()
{
    ThreadPool pool(4);

    // 创建多个任务并提交给线程池执行
    for (int i = 0; i < 8; ++i)
    {
        pool.enqueue([i] {
            // 模拟任务的执行，这里只是简单地输出任务的执行结果
            cout << "Task " << i << " is running." << endl;
        });
    }

    return 0;
}
