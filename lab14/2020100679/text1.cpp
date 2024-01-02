#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <random>

class BankAccount {
public:
    BankAccount(int id, int initialBalance) : id(id), balance(initialBalance) {}

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
        std::cout << "Deposited " << amount << " to account " << id << ". New balance: " << balance << std::endl;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn " << amount << " from account " << id << ". New balance: " << balance << std::endl;
        }
        else {
            std::cout << "Insufficient funds for account " << id << ". Balance: " << balance << std::endl;
        }
    }

    int getBalance() {
        std::lock_guard<std::mutex> lock(mtx);
        return balance;
    }

    int getId() {
        return id;
    }

private:
    int id;
    int balance;
    std::mutex mtx;
};

void randomOperation(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> amountDist(1, 100);
    std::uniform_int_distribution<int> actionDist(0, 1);

    for (int i = 0; i < 10; ++i) {
        int action = actionDist(gen);
        int amount = amountDist(gen);
        if (action == 0) {
            account.deposit(amount);
        }
        else {
            account.withdraw(amount);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    BankAccount account1(1, 1000);
    BankAccount account2(2, 1000);

    std::thread t1(randomOperation, std::ref(account1));
    std::thread t2(randomOperation, std::ref(account2));

    t1.join();
    t2.join();

    std::cout << "Final balance for account" << account1.getId() << ": " << account1.getBalance() << std::endl;
    std::cout << "Final balance for account" << account2.getId() << ": " << account2.getBalance() << std::endl;

    return 0;
}