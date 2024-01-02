#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

class BankAccount {  
public:  
    BankAccount(int balance) : balance(balance) {}  

    void deposit(int amount) {  
        unique_lock<mutex> lock(mutex_);  
        balance += amount;  
        cout << "存款数：" << amount << ",余额数：" << balance <<endl;  
    }  

    void withdraw(int amount) {  
        unique_lock<mutex> lock(mutex_);  
        if(balance >= amount) {  
            balance -= amount;  
            cout << "取款数：" << amount << ",余额数：" << balance <<endl;  
        } else {  
            cout << "余额不足!余额数：" << balance<<endl;  
        }  
    }  
    private:  
    int balance;  
    mutex mutex_;  
}; 

void depositThread(BankAccount& account) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> amountDistribution(1, 100);
    uniform_int_distribution<int> sleepDistribution(1, 5);

    while (true) {
        int amount = amountDistribution(generator);
        this_thread::sleep_for(chrono::seconds(sleepDistribution(generator)));
        account.deposit(amount);
    }
}

void withdrawThread(BankAccount& account) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> amountDistribution(1, 100);
    uniform_int_distribution<int> sleepDistribution(1, 5);

    while (true) {
        int amount = amountDistribution(generator);
        this_thread::sleep_for(chrono::seconds(sleepDistribution(generator)));
        account.withdraw(amount);
    }
}

int main() {
    BankAccount account(1000);
    thread deposit(depositThread,ref(account));
    thread withdraw(withdrawThread,ref(account));
    deposit.join();
    withdraw.join();
    return 0;
}