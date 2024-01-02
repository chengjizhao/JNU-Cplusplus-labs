#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>

class BankAccount {
public:
    BankAccount(int initialBalance) : balance(initialBalance) {}

    int getBalance() const {
        return balance;
    }

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(accountMutex);
        balance += amount;
        std::cout << "Deposit: " << amount << ", New Balance: " << balance << std::endl;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(accountMutex);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdraw: " << amount << ", New Balance: " << balance << std::endl;
        } else {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }

private:
    int balance;
    std::mutex accountMutex;
};

void depositThread(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(amountDistribution(gen)));
        int amount = amountDistribution(gen);
        account.deposit(amount);
    }
}

void withdrawThread(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(amountDistribution(gen)));
        int amount = amountDistribution(gen);
        account.withdraw(amount);
    }
}

int main() {
    BankAccount account(1000);

    // 创建存款和取款线程
    std::thread depositT(depositThread, std::ref(account));
    std::thread withdrawT(withdrawThread, std::ref(account));

    // 等待线程完成
    depositT.join();
    withdrawT.join();

    return 0;
}
