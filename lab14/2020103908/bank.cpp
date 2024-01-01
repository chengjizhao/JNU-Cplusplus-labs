#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include <chrono>

class BankAccount {
public:
    BankAccount(int initialBalance) : balance(initialBalance) {}

    int getBalance() const {
        return balance;
    }

    void deposit(int amount) {
        std::unique_lock<std::mutex> lock(accountMutex);
        balance += amount;
        std::cout << "Deposited $" << amount << ". New balance: $" << balance << std::endl;
    }

    void withdraw(int amount) {
        std::unique_lock<std::mutex> lock(accountMutex);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << ". New balance: $" << balance << std::endl;
        } else {
            std::cout << "Withdrawal failed. Insufficient funds. Balance: $" << balance << std::endl;
        }
    }

private:
    int balance;
    std::mutex accountMutex;
};

void randomDeposit(std::vector<BankAccount>& accounts) {
    std::srand(static_cast<unsigned int>(std::time(0)));

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 1000));

        int accountIndex = std::rand() % accounts.size();
        int depositAmount = std::rand() % 100 + 1;

        accounts[accountIndex].deposit(depositAmount);
    }
}

void randomWithdraw(std::vector<BankAccount>& accounts) {
    std::srand(static_cast<unsigned int>(std::time(0)));

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 1000));

        int accountIndex = std::rand() % accounts.size();
        int withdrawAmount = std::rand() % 100 + 1;

        accounts[accountIndex].withdraw(withdrawAmount);
    }
}

int main() {
    const int numAccounts = 5; // Number of bank accounts
    std::vector<BankAccount> accounts;

    // Initialize bank accounts
    for (int i = 0; i < numAccounts; ++i) {
        accounts.emplace_back(1000);
    }

    // Create threads for deposit and withdrawal
    std::thread depositThread(randomDeposit, std::ref(accounts));
    std::thread withdrawThread(randomWithdraw, std::ref(accounts));

    // Join threads
    depositThread.join();
    withdrawThread.join();

    return 0;
}
