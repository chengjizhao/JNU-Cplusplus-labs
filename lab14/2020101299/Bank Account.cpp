#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <chrono>

class Account {
private:
    int balance; 
    std::mutex m; 
public:
    Account(int initial) : balance(initial) {}
    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(m);
        balance += amount;
        std::cout << "存入 " << amount << " 元，当前余额为 " << balance << " 元\n";
    }
    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(m);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "取出 " << amount << " 元，当前余额为 " << balance << " 元\n";
        } else {
            std::cout << "余额不足，无法取出 " << amount << " 元，当前余额为 " << balance << " 元\n";
        }
    }
};

std::random_device rd; 
std::mt19937 gen(rd()); 
std::uniform_int_distribution<> dis(1, 100); 

void deposit_thread(std::vector<Account*>& accounts) {
    while (true) {
        int index = dis(gen) % accounts.size();
        int amount = dis(gen);
        accounts[index]->deposit(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen)));
    }
}

void withdraw_thread(std::vector<Account*>& accounts) {
    while (true) {
        int index = dis(gen) % accounts.size();
        int amount = dis(gen);
        accounts[index]->withdraw(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen)));
    }
}

int main() {
    std::vector<Account*> accounts;
    for (int i = 0; i < 10; i++) {
        accounts.push_back(new Account(1000));
    }
    std::thread t1(deposit_thread, accounts);
    std::thread t2(withdraw_thread, accounts);
    t1.join();
    t2.join();
    for (auto account : accounts) {
        delete account;
    }
    return 0;
}