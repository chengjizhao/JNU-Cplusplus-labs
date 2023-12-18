#include <iostream>
#include <thread>
#include <mutex>
#include <random>

using namespace std;

const int MAX_ACCOUNT = 10;
const int MAX_AMOUNT = 100;

struct Account {
    int id;
    int balance;
};

Account accounts[MAX_ACCOUNT];

mutex mtx;

void deposit(Account &account, int amount) {
    lock_guard<mutex> lock(mtx);
    account.balance += amount;
    cout << "Account " << account.id << " balance: " << account.balance << endl;
}

void withdraw(Account &account, int amount) {
    lock_guard<mutex> lock(mtx);
    if (account.balance >= amount) {
        account.balance -= amount;
        cout << "Account " << account.id << " balance: " << account.balance << endl;
    } else {
        cout << "Insufficient balance" << endl;
    }
}

void depositThread() {
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<> dis(1, MAX_ACCOUNT);

    while (true) {
        int accountId = dis(gen);
        Account &account = accounts[accountId];
        int amount = dis(gen) % MAX_AMOUNT + 1;
        deposit(account, amount);
        cout << "Deposited " << amount << " to account " << account.id << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void withdrawThread() {
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<> dis(1, MAX_ACCOUNT);

    while (true) {
        int accountId = dis(gen);
        Account &account = accounts[accountId];
        int amount = dis(gen) % MAX_AMOUNT + 1;
        withdraw(account, amount);
        cout << "Withdrew " << amount << " from account " << account.id << endl;
        if (account.balance < 0) {
            cout << "Account " << account.id << " balance: " << account.balance << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    //10个账户，初始余额1000元
    for (int i = 0; i < MAX_ACCOUNT; ++i) {
        accounts[i].id = i + 1;
        accounts[i].balance = 1000;
    }

    thread depositThread1(depositThread);
    thread withdrawThread1(withdrawThread);

    depositThread1.join();
    withdrawThread1.join();

    return 0;
}