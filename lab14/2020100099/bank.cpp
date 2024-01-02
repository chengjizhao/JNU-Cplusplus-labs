#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <chrono>

class BankAccount {
public:
    BankAccount(int id, int balance) : id(id), balance(balance) {}

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
        std::cout << "Deposit " << amount << " to account " << id << ", current balance: " << balance << std::endl;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdraw " << amount << " from account " << id << ", current balance: " << balance << std::endl;
        } else {
            std::cout << "Not enough balance in account " << id << std::endl;
        }
    }

private:
    int id;
    int balance;
    std::mutex mtx;
};

void depositAndWithdraw(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> amount_distribution(1, 100);
    std::uniform_int_distribution<int> time_distribution(100, 1000);

    for (int i = 0; i < 10; ++i) {
        int amount = amount_distribution(gen);
        account.deposit(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(time_distribution(gen)));

        amount = amount_distribution(gen);
        account.withdraw(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(time_distribution(gen)));
    }
}

int main() {
    BankAccount account1(1, 1000);
    BankAccount account2(2, 1000);

    std::thread thread1(depositAndWithdraw, std::ref(account1));
    std::thread thread2(depositAndWithdraw, std::ref(account2));

    thread1.join();
    thread2.join();

    return 0;
}