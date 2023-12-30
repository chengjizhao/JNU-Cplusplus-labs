#include <iostream>  
#include <vector>  
#include <thread>  
#include <mutex>  
#include <random>   
#include <chrono>  
  
// 定义一个名为BankAccount的类，表示银行账户。  
class BankAccount {  
public:  
    // 构造函数，初始化账户余额为给定的初始金额。  
    BankAccount(int initialBalance) : balance(initialBalance) {}  
  
    // 存款函数，允许将一定金额存入账户。使用互斥量保护对账户余额的访问，以避免竞态条件。  
    void deposit(int amount) {  
        std::lock_guard<std::mutex> lock(accountMutex);  // 使用lock_guard智能锁管理互斥量，确保在函数结束时释放锁。  
        balance += amount;  // 更新账户余额。  
        std::cout << "Deposited " << amount << " yuan. New balance: " << balance << " yuan." << std::endl;  // 输出存款信息。  
    }  
  
    // 取款函数，允许从账户中取出一定金额。同样使用互斥量保护对账户余额的访问。如果余额不足，则不进行取款操作。  
    void withdraw(int amount) {  
        std::lock_guard<std::mutex> lock(accountMutex);  // 使用lock_guard智能锁管理互斥量，确保在函数结束时释放锁。  
        if (balance >= amount) {  // 检查余额是否足够进行取款操作。  
            balance -= amount;  // 更新账户余额。  
            std::cout << "Withdrawn " << amount << " yuan. New balance: " << balance << " yuan." << std::endl;  // 输出取款信息。  
        } else {  // 如果余额不足，则输出错误信息。  
            std::cout << "Insufficient funds for withdrawal. Balance: " << balance << " yuan." << std::endl;  
        }  
    }  
  
private:  
    // 账户余额变量，存储账户中的金额。  
    int balance;  
    // 互斥量，用于保护对账户余额的访问，避免竞态条件。  
    std::mutex accountMutex;  
};  
  
// 定义一个名为randomDeposit的函数，模拟随机存款操作。该函数接受一个BankAccount对象的引用作为参数。  
void randomDeposit(BankAccount& account) {  
    // 使用随机设备作为随机数生成器的种子。  
    std::random_device rd;  
    // 使用Mersenne Twister算法生成随机数。  
    std::mt19937 gen(rd());  
    // 定义一个均匀分布的整数分布器，用于生成1到100之间的随机数。  
    std::uniform_int_distribution<int> amountDistribution(1, 100);  
    // 定义另一个均匀分布的整数分布器，用于生成100到1000之间的随机数，作为存款和取款操作之间的时间间隔。  
    std::uniform_int_distribution<int> timeDistribution(100, 1000);  
  
    // 创建一个无限循环，模拟连续的随机存款操作。  
    while (true) {  // 无限循环，持续进行存款操作。  
        int amount = amountDistribution(gen);  // 生成随机存款金额。  
        std::this_thread::sleep_for(std::chrono::milliseconds(timeDistribution(gen)));  // 当前线程睡眠一段时间，模拟操作间隔。  
        account.deposit(amount);  // 在模拟账户中执行存款操作。  
    }  // while循环结束。由于while循环是无限的，所以需要使用外部手段（如ctrl+c）终止程序执行。
}

void randomWithdraw(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);
    std::uniform_int_distribution<int> timeDistribution(100, 1000);

    while (true) {
        int amount = amountDistribution(gen);
        std::this_thread::sleep_for(std::chrono::milliseconds(timeDistribution(gen)));
        account.withdraw(amount);
    }
}

int main() {
    BankAccount account(100);

    // 启动存款和取款线程
    std::thread depositThread(randomDeposit, std::ref(account));
    std::thread withdrawThread(randomWithdraw, std::ref(account));

    // 主线程等待存款和取款线程结束
    depositThread.join();
    withdrawThread.join();

    return 0;
}