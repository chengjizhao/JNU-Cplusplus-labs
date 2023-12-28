#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <mutex>

class BankAccount {
public:
    BankAccount(int initialBalance) : balance(initialBalance) {}

    void deposit(int amount) 
    {
        std::lock_guard<std::mutex> lock(mutex);
        balance += amount;
        std::cout << "Deposited $" << amount << ", current balance: $" << balance << std::endl;
    }

    void withdraw(int amount) 
    {
        std::lock_guard<std::mutex> lock(mutex);
        if (balance >= amount) 
        {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << ", current balance: $" << balance << std::endl;
        } 
        else 
        {
            std::cout << "Insufficient balance to withdraw $" << amount << ", current balance: $" << balance << std::endl;
        }
    }

private:
    int balance;
    std::mutex mutex;
};

void depositRandomAmount(BankAccount& account) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);
    std::uniform_int_distribution<int> sleepDistribution(100, 1000);

    while (true) 
    {
        int amount = amountDistribution(gen);
        account.deposit(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepDistribution(gen)));
    }
}

void withdrawRandomAmount(BankAccount& account) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> amountDistribution(1, 100);
    std::uniform_int_distribution<int> sleepDistribution(100, 1000);

    while (true) 
    {
        int amount = amountDistribution(gen);
        account.withdraw(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepDistribution(gen)));
    }
}

int main() 
{
    BankAccount account(1000);

    std::vector<std::thread> threads;
    threads.emplace_back(depositRandomAmount, std::ref(account));
    threads.emplace_back(withdrawRandomAmount, std::ref(account));

    for (auto& thread : threads) 
    {
        thread.join();
    }

    return 0;
}
