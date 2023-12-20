#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <chrono>

class BankAccount {
public:
    BankAccount(int id, double balance) : id(id), balance(balance), mtx() {}

    void deposit(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
        std::cout << "Deposited " << amount << " to account " << id << ", new balance: " << balance << std::endl;
    }

    void withdraw(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn " << amount << " from account " << id << ", new balance: " << balance << std::endl;
        }
        else {
            std::cout << "Insufficient funds to withdraw " << amount << " from account " << id << ", balance: " << balance << std::endl;
        }
    }

    int getId() const {
        return id;
    }

private:
    int id;
    double balance;
    std::mutex mtx;
};

void depositRandom(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 100.0);

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        double amount = dis(gen);
        account.deposit(amount);
    }
}

void withdrawRandom(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 100.0);

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        double amount = dis(gen);
        account.withdraw(amount);
    }
}

int main() {
    BankAccount account(1, 1000); 
    std::thread depositThread(depositRandom, std::ref(account));
    std::thread withdrawThread(withdrawRandom, std::ref(account)); 

    depositThread.join();
    withdrawThread.join();

    return 0;
}
