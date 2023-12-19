#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <chrono>

class BankAccount {
public:
    explicit BankAccount(int initialBalance) : balance(initialBalance) {}

    int getBalance() const {
        return balance;
    }

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(mutex);
        balance += amount;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mutex);
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }

private:
    int balance;
    std::mutex mutex;
};

void depositRandomAmount(BankAccount& account) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);
    std::uniform_int_distribution<int> sleepDistribution(100, 1000);

    while (true) {
        int amount = amountDistribution(rng);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepDistribution(rng)));
        account.deposit(amount);
        std::cout << "Deposited " << amount << " yuan. New balance: " << account.getBalance() << " yuan." << std::endl;
    }
}

void withdrawRandomAmount(BankAccount& account) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);
    std::uniform_int_distribution<int> sleepDistribution(100, 1000);

    while (true) {
        int amount = amountDistribution(rng);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepDistribution(rng)));
        account.withdraw(amount);
        std::cout << "Withdrawn " << amount << " yuan. New balance: " << account.getBalance() << " yuan." << std::endl;
    }
}

int main() {
    BankAccount account(1000);

    std::vector<std::thread> threads;
    threads.emplace_back(depositRandomAmount, std::ref(account));
    threads.emplace_back(withdrawRandomAmount, std::ref(account));

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
