#include <iostream>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>

class BankAccount {
public:
    BankAccount(int initialBalance) : balance(initialBalance) {}

    int getBalance() {
        return balance;
    }

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(mutex);
        balance += amount;
        std::cout << "Deposited " << amount << " yuan. Current balance: " << balance << " yuan." << std::endl;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mutex);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn " << amount << " yuan. Current balance: " << balance << " yuan." << std::endl;
        } else {
            std::cout << "Insufficient funds to withdraw " << amount << " yuan. Current balance: " << balance << " yuan." << std::endl;
        }
    }

private:
    int balance;
    std::mutex mutex;
};

void depositThread(BankAccount& account) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);
    std::uniform_int_distribution<int> sleepDistribution(1, 5);

    while (true) {
        int amount = amountDistribution(generator);
        std::this_thread::sleep_for(std::chrono::seconds(sleepDistribution(generator)));
        account.deposit(amount);
    }
}

void withdrawThread(BankAccount& account) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);
    std::uniform_int_distribution<int> sleepDistribution(1, 5);

    while (true) {
        int amount = amountDistribution(generator);
        std::this_thread::sleep_for(std::chrono::seconds(sleepDistribution(generator)));
        account.withdraw(amount);
    }
}

int main() {
    BankAccount account(1000);

    std::thread depositT(depositThread, std::ref(account));
    std::thread withdrawT(withdrawThread, std::ref(account));

    depositT.join();
    withdrawT.join();

    return 0;
}
