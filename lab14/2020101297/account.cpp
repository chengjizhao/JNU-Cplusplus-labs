#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <random>
#include <chrono>

class BankAccount {
public:
    BankAccount(int initialBalance) : balance(initialBalance) {}

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(mutex);
        balance += amount;
        std::cout << "Deposit: " << amount << " Balance: " << balance << std::endl;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mutex);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdraw: " << amount << " Balance: " << balance << std::endl;
        } else {
            std::cout << "Withdraw failed: Insufficient balance" << std::endl;
        }
    }

private:
    int balance;
    std::mutex mutex;
};

void depositRandom(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);
    std::uniform_int_distribution<int> delayDistribution(100, 1000);

    while (true) {
        int amount = amountDistribution(gen);
        std::this_thread::sleep_for(std::chrono::milliseconds(delayDistribution(gen)));
        account.deposit(amount);
    }
}

void withdrawRandom(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);
    std::uniform_int_distribution<int> delayDistribution(100, 1000);

    while (true) {
        int amount = amountDistribution(gen);
        std::this_thread::sleep_for(std::chrono::milliseconds(delayDistribution(gen)));
        account.withdraw(amount);
    }
}

int main() {
    BankAccount account(1000);

    std::thread depositThread(depositRandom, std::ref(account));
    std::thread withdrawThread(withdrawRandom, std::ref(account));

    depositThread.join();
    withdrawThread.join();

    return 0;
}
