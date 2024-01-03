#include <iostream>  
#include <thread>  
#include <mutex>  
#include <random>  
#include <chrono>  
#include <vector>  
  
class BankAccount {  
public:  
    BankAccount(int balance) : balance(balance) {}  
  
    void deposit(int amount) {  
        std::unique_lock<std::mutex> lock(mutex_);  
        balance += amount;  
        std::cout << "Deposited " << amount << ", balance is now " << balance << std::endl;  
    }  
  
    void withdraw(int amount) {  
        std::unique_lock<std::mutex> lock(mutex_);  
        if(balance >= amount) {  
            balance -= amount;  
            std::cout << "Withdrew " << amount << ", balance is now " << balance << std::endl;  
        } else {  
            std::cout << "Insufficient funds!" << std::endl;  
        }  
    }  
  
private:  
    int balance;  
    std::mutex mutex_;  
};  
  
void depositThread(BankAccount& account, std::default_random_engine& generator) {  
    while (true) {  
        std::uniform_int_distribution<int> distribution(1, 100);  
        int amount = distribution(generator);  
        account.deposit(amount);  
        std::this_thread::sleep_for(std::chrono::milliseconds(generator() % 1000));   
    }  
}  
  
void withdrawThread(BankAccount& account, std::default_random_engine& generator) {  
    while (true) {  
        std::uniform_int_distribution<int> distribution(1, 100);  
        int amount = distribution(generator);  
        account.withdraw(amount);  
        std::this_thread::sleep_for(std::chrono::milliseconds(generator() % 1000));  
    }  
}  
  
int main() {  
    std::default_random_engine generator;  
    BankAccount account(1000);   
    std::thread depositThread(depositThread, account, generator);   
    std::thread withdrawThread(withdrawThread, account, generator);   
    depositThread.join();   
    withdrawThread.join(); // 等待提取线程完成 
    return 0;  
}
