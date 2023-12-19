#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>
using namespace std;
mutex mtx;

class Account
{
    public:
       Account(int balance_) : balance(balance_) {}
       void withdraw(int amount, int Id) 
       {
        lock_guard<mutex> lock(mtx);
        cout << "Withdraw $" << amount << " from Account " << Id << endl;
        balance = balance - amount;
        cout << "---Account " << Id << ": $" << balance << endl;
        }
       void deposit(int amount, int Id) 
       {
        lock_guard<mutex> lock(mtx);
        cout << "Deposit $" << amount << " to Account " << Id << endl;
        balance = balance + amount;
        cout << "---Account " << Id << ": $" << balance << endl;
        }
        
    private:
        int balance;
};

void random_withdraw(Account* account, int Id) 
{
    int amount = rand() % 100;
    account -> withdraw(amount, Id);
}

void random_deposit(Account* account, int Id) 
{
    int amount = rand() % 100;
    account->deposit(amount, Id);
}

void random_account(void (*f)(Account*, int), int n, Account* account) 
{
    for (int i = 0; i < n; i=i+1) 
    {
        f(account, rand() % 9);
        this_thread::sleep_for(chrono::milliseconds(rand() % 100));
    }
}

int main() 
{
    srand(time(nullptr));
    vector<Account> accounts;
    for (int i = 0; i < 10; ++i) 
    {
        accounts.emplace_back(1000);
    }

    thread withdraw_thread(random_account, random_withdraw, 5, &accounts[0]);
    thread deposit_thread(random_account, random_deposit, 5, &accounts[0]);

    withdraw_thread.join();
    deposit_thread.join();

    return 0;
}
