#include <iostream>  
#include <thread>  
#include <mutex>  
#include <random>  
#include <vector>  
#include <chrono>  
  
class Account {  
public:  
    Account(int balance = 1000) : balance(balance) {}  
    void deposit(int amount) {  
        std::lock_guard<std::mutex> lock(mtx);  
        balance += amount;  
        std::cout << "Deposit " << amount << " to account " << balance << std::endl;  
    }  
    void withdraw(int amount) {  
        std::lock_guard<std::mutex> lock(mtx);  
        if (amount > balance) {  
            std::cout << "Insufficient funds" << std::endl;  
            return;  
        }  
        balance -= amount;  
        std::cout << "Withdraw " << amount << " from account " << balance << std::endl;  
    }  
private:  
    int balance;  
    std::mutex mtx; 
};  
  
void deposit(Account& account, int amount) {  
    account.deposit(amount);  
}  
void withdraw(Account& account, int amount) {  
    account.withdraw(amount);  
}  
  
int main() {  
    const int numAccounts = 10;  
    const int maxAmount = 100;  
    const int maxThreads = 2; 
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    Account accounts[numAccounts]; 
    std::vector<std::thread> threads;  
    while (threads.size() < maxThreads) {  
        int whichAccount = gen() % numAccounts; 
        int howmuch = std::uniform_int_distribution<int>(1, maxAmount)(gen); 
        if (whichAccount % 2 == 0) { 
            threads.push_back(std::thread(deposit, std::ref(accounts[whichAccount]), howmuch));  
        } else {  
            threads.push_back(std::thread(withdraw, std::ref(accounts[whichAccount]), howmuch));  
        }  
    }  
    for (auto& t : threads) { 
        t.join();  
    }  
    return 0;  
}