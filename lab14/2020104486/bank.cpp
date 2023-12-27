#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>

class BankAccount {
public:
 BankAccount(int initialBalance) : balance(initialBalance) {}

 int getBalance() const {
 return balance;
 }

 void deposit(int amount) {
 std::lock_guard<std::mutex> lock(mtx);
 balance += amount;
 }

 void withdraw(int amount) {
 std::lock_guard<std::mutex> lock(mtx);
 balance -= amount;
 }

private:
 int balance;
 std::mutex mtx;
};

void depositThread(BankAccount& account) {
 std::random_device rd;
 std::mt19937 gen(rd());
 std::uniform_int_distribution<int> amountDist(1,100);
 std::uniform_int_distribution<int> sleepDist(1,5);

 while (true) {
 int amount = amountDist(gen);
 account.deposit(amount);
 std::cout << "Deposited " << amount << " yuan. New balance: " << account.getBalance() << " yuan." << std::endl;

 std::this_thread::sleep_for(std::chrono::seconds(sleepDist(gen)));
 }
}

void withdrawThread(BankAccount& account) {
 std::random_device rd;
 std::mt19937 gen(rd());
 std::uniform_int_distribution<int> amountDist(1,100);
 std::uniform_int_distribution<int> sleepDist(1,5);

 while (true) {
 int amount = amountDist(gen);
 if (account.getBalance() >= amount) {
 account.withdraw(amount);
 std::cout << "Withdrawn " << amount << " yuan. New balance: " << account.getBalance() << " yuan." << std::endl;
 }

 std::this_thread::sleep_for(std::chrono::seconds(sleepDist(gen)));
 }
}

int main() {
 BankAccount account(1000);

 std::thread depositThread(depositThread, std::ref(account));
 std::thread withdrawThread(withdrawThread, std::ref(account));

 depositThread.join();
 withdrawThread.join();

 return 0;
}
