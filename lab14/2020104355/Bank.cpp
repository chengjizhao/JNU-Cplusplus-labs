#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>

class BankAccount {
public:
    BankAccount(int initialBalance) : balance(initialBalance) {}

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(accountMutex);
        balance += amount;
        std::cout << "Deposited " << amount << " yuan. New balance: " << balance << " yuan." << std::endl;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(accountMutex);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn " << amount << " yuan. New balance: " << balance << " yuan." << std::endl;
        } else {
            std::cout << "Insufficient funds for withdrawal. Balance: " << balance << " yuan." << std::endl;
        }
    }

private:
    int balance;
    std::mutex accountMutex;
};

void randomDeposit(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);
    std::uniform_int_distribution<int> timeDistribution(100, 1000);

    while (true) {
        int amount = amountDistribution(gen);
        std::this_thread::sleep_for(std::chrono::milliseconds(timeDistribution(gen)));
        account.deposit(amount);
    }
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
    BankAccount account(1000);

    // 启动存款和取款线程
    std::thread depositThread(randomDeposit, std::ref(account));
    std::thread withdrawThread(randomWithdraw, std::ref(account));

    // 主线程等待存款和取款线程结束
    depositThread.join();
    withdrawThread.join();

    return 0;
}