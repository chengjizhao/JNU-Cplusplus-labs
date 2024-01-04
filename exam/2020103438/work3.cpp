#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <random>
/*使用C++标准库创建1个生产者线程和4个消费者线程。

实现一个线程安全的队列，队列最多存20条数据，生产者线程每秒内向队列中添加3个数据，消
费者线程每次从队列中取出一个数据，每次取走一个数据后，随机等待1或者2
秒后再取。使用条件变量确保在队列为空时，消费者线程等待，队列为满时，生产者线程等待。 
输出生产者生产的数据和消费者消费的数据。*/
std::mutex mtx;
std::condition_variable cv;
std::queue<int> q;
const int max_q_size = 20;

void producer() {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,100);//随机数分布对象
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));//每秒生产3个
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{return q.size() < max_q_size;});
        for(int i = 0; i < 3; ++i) //
        {
            int value = distribution(generator);
            q.push(value);
            std::cout << "产生数据: " << value << std::endl;
        }
        lock.unlock();
        cv.notify_all();
    }
}

void consumer(int id) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,2);//随机数分布对象
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{return !q.empty();});//等待条件变量通知
        int value = q.front();
        q.pop();//取出数据
        std::cout << "消费者 " << id << ":取出 " << value << std::endl;
        lock.unlock();
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::seconds(distribution(generator)));
    }
}

int main() {
    std::thread prod(producer);//生产者线程
    std::thread t1(consumer, 1);//消费者线程
    std::thread t2(consumer, 2);
    std::thread t3(consumer, 3);
    std::thread t4(consumer, 4);

    prod.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}