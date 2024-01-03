#include <iostream>  
#include <thread>  
#include <mutex>  
#include <condition_variable>  
#include <random>  
#include <chrono>  

class BankAccount {
public:
    BankAccount(int id) : id(id), balance(1000) {}

    void deposit(int amount) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return amount <= balance; }); // 等待余额足够  
        balance += amount;
        std::cout << "Account " << id << " deposit: " << amount << ", balance: " << balance << std::endl;
        lock.unlock();
        cv.notify_one(); // 通知取款操作  
    }

    void withdraw(int amount) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return amount <= balance; }); // 等待余额足够  
        balance -= amount;
        std::cout << "Account " << id << " withdraw: " << amount << ", balance: " << balance << std::endl;
        lock.unlock();
        cv.notify_one(); // 通知存款操作或其他取款操作  
    }

private:
    int id;
    int balance;
    std::mutex mtx; // 互斥锁，确保线程安全  
    std::condition_variable cv; // 条件变量，用于线程同步  
};

void deposit_to_random_account(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd()); // 随机数生成器  
    std::uniform_int_distribution<> dis(1, 100); // 取款范围在1元到100元之间  
    for (int i = 0; i < 100; ++i) { // 执行100次存款操作  
        account.deposit(dis(gen)); // 随机存款金额  
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 5 + 1)); // 随机时间间隔在1毫秒到5毫秒之间  
    }
}

void withdraw_from_random_account(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd()); // 随机数生成器  
    std::uniform_int_distribution<> dis(1, 100); // 取款范围在1元到100元之间  
    for (int i = 0; i < 100; ++i) { // 执行100次取款操作  
        account.withdraw(dis(gen)); // 随机取款金额  
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 5 + 1)); // 随机时间间隔在1毫秒到5毫秒之间  
    }
}

int main() {
    BankAccount account1(1); // 创建账户1，初始余额为1000元  
    BankAccount account2(2); // 创建账户2，初始余额为1000元（实际程序中可以创建多个账户）  
    std::thread t1(&deposit_to_random_account, std::ref(account1)); // 启动线程执行存款操作到账户1中  
    std::thread t2(&withdraw_from_random_account, std::ref(account2)); // 启动线程执行取款操作从账户2中  
    t1.join(); // 等待线程t1执行完成  
    t2.join(); // 等待线程t2执行完成  
    return 0;
}