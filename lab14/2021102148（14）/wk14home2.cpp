#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class BankAccount
{
public:
    BankAccount(int id, int initialBalance) : accountID(id), balance(initialBalance) {}

    int getBalance() const
    {
        return balance;
    }

    void deposit(int amount)
    {
        std::lock_guard<std::mutex> lock(accountMutex);
        std::cout << "Thread-" << std::this_thread::get_id() << " Deposit " << amount << " into Account-" << accountID << std::endl;
        balance += amount;
    }

    void withdraw(int amount)
    {
        std::lock_guard<std::mutex> lock(accountMutex);
        std::cout << "Thread-" << std::this_thread::get_id() << " Withdraw " << amount << " from Account-" << accountID << std::endl;
        balance -= amount;
    }

private:
    int accountID;
    int balance;
    std::mutex accountMutex;
};

void depositThread(BankAccount &account)
{
    while (true)
    {
        int amount = rand() % 100 + 1; // Random deposit amount between 1 and 100
        account.deposit(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000 + 500)); // Random sleep between 500ms and 1500ms
    }
}

void withdrawThread(BankAccount &account)
{
    while (true)
    {
        int amount = rand() % 100 + 1; // Random withdraw amount between 1 and 100
        account.withdraw(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000 + 500)); // Random sleep between 500ms and 1500ms
    }
}

int main()
{
    std::srand(std::time(0));

    BankAccount account1(1, 1000);
    BankAccount account2(2, 1000);

    std::thread depositThread1(depositThread, std::ref(account1));
    std::thread depositThread2(depositThread, std::ref(account2));
    std::thread withdrawThread1(withdrawThread, std::ref(account1));
    std::thread withdrawThread2(withdrawThread, std::ref(account2));

    depositThread1.join();
    depositThread2.join();
    withdrawThread1.join();
    withdrawThread2.join();

    return 0;
}
