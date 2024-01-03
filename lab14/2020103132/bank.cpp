#include <iostream>  
#include <thread>  
#include <mutex>  
#include <random>  
#include <vector>  
  
class BankAccount 
{  
public:  
    BankAccount() : balance(1000) {}  
  
    void deposit(int amount) 
    {  
        std::lock_guard<std::mutex> lock(mtx);  
        balance += amount;  
        std::cout << "Deposited " << amount << " into account " << id << ", balance is now " << balance << std::endl;  
    }  
  
    void withdraw(int amount) 
    {  
        std::lock_guard<std::mutex> lock(mtx);  
        if (balance >= amount) 
        {  
            balance -= amount;  
            std::cout << "Withdrew " << amount << " from account " << id << ", balance is now " << balance << std::endl;  
        } 
        else 
        {  
            std::cout << "Insufficient funds in account " << id << std::endl;  
        }  
    }  
  
private:  
    int balance;  
    int id; // 账户ID，用于标识不同的账户  
    std::mutex mtx; // 互斥锁，用于保护共享数据  
};  
  
void depositThread(std::vector<BankAccount>& accounts) 
{  
    std::default_random_engine generator;  
    std::uniform_int_distribution<int> distribution(1, 100); // 随机生成1到100之间的整数，表示存款或取款的金额  
  
    while (true) 
    {  
        int accountIndex = generator() % accounts.size(); // 随机选择一个账户进行存款操作  
        int amount = distribution(generator); // 随机生成存款金额  
        accounts[accountIndex].deposit(amount); // 进行存款操作  
        std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); // 随机时间间隔，范围在0到4秒之间  
    }  
}  
  
void withdrawThread(std::vector<BankAccount>& accounts) 
{  
    std::default_random_engine generator;  
    std::uniform_int_distribution<int> distribution(1, 100); // 随机生成1到100之间的整数，表示存款或取款的金额  
  
    while (true) 
    {  
        int accountIndex = generator() % accounts.size(); // 随机选择一个账户进行取款操作  
        int amount = distribution(generator); // 随机生成取款金额  
        accounts[accountIndex].withdraw(amount); // 进行取款操作  
        std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); // 随机时间间隔，范围在0到4秒之间  
    }  
}  
  
int main() 
{  
    const int numAccounts = 5; // 假设有5个账户可供操作  
    std::vector<BankAccount> accounts(numAccounts); // 创建5个账户对象，初始余额为1000元  
    std::thread depositThreadObj(depositThread, std::ref(accounts)); // 启动存款线程，传入账户对象的引用作为参数  
    std::thread withdrawThreadObj(withdrawThread, std::ref(accounts)); // 启动取款线程，传入账户对象的引用作为参数  
    depositThreadObj.join(); // 等待存款线程结束  
    withdrawThreadObj.join(); // 等待取款线程结束  
    return 0;  
}