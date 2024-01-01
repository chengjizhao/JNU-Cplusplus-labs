#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <chrono>
#include <random>

class BankAccount {
public:
    BankAccount(int initialBalance) : balance(initialBalance) {}

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
        std::cout << "Deposit: " << amount << " - New balance: " << balance << std::endl;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal: " << amount << " - New balance: " << balance << std::endl;
        } else {
            std::cout << "Insufficient funds for withdrawal" << std::endl;
        }
    }

private:
    int balance;
    std::mutex mtx;
};

int main() {
    std::vector<BankAccount> accounts{BankAccount(1000), BankAccount(1000), BankAccount(1000)};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> accountDistribution(0, 2);
    std::uniform_int_distribution<int> amountDistribution(1, 100);

    std::thread t1([&accounts, &gen, &accountDistribution, &amountDistribution](){
        while (true) {
            int accountIndex = accountDistribution(gen);
            accounts[accountIndex].deposit(amountDistribution(gen));
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
    });

    std::thread t2([&accounts, &gen, &accountDistribution, &amountDistribution](){
        while (true) {
            int accountIndex = accountDistribution(gen);
            accounts[accountIndex].withdraw(amountDistribution(gen));
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        }
    });

    t1.join();
    t2.join();

    return 0;
}