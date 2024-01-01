#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
#include <cstdlib>

using namespace std;

const int NUM_ACCOUNTS = 5;
const int INITIAL_BALANCE = 1000;
const int MIN_AMOUNT = 1;
const int MAX_AMOUNT = 100;

mutex accountMutex[NUM_ACCOUNTS];

class BankAccount {
public:
    BankAccount() : balance(INITIAL_BALANCE) {}

    int getBalance() const {
        return balance;
    }

    void deposit(int amount) {
        lock_guard<mutex> lock(accountMutex[id]);
        balance += amount;
        cout << "Deposited " << amount << " yuan into account " << id << ". New balance: " << balance << " yuan." << endl;
    }

    void withdraw(int amount) {
        lock_guard<mutex> lock(accountMutex[id]);
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn " << amount << " yuan from account " << id << ". New balance: " << balance << " yuan." << endl;
        } else {
            cout << "Insufficient funds in account " << id << " to withdraw " << amount << " yuan." << endl;
        }
    }

private:
    int balance = 0;
    static int idCounter;
    int id = idCounter++;
};

int BankAccount::idCounter = 0;

void depositThread(BankAccount* accounts) {
    while (true) {
        int accountIndex = rand() % NUM_ACCOUNTS;
        int depositAmount = rand() % (MAX_AMOUNT - MIN_AMOUNT + 1) + MIN_AMOUNT;
        accounts[accountIndex].deposit(depositAmount);
        this_thread::sleep_for(chrono::milliseconds(rand() % 1000));
    }
}

void withdrawThread(BankAccount* accounts) {
    while (true) {
        int accountIndex = rand() % NUM_ACCOUNTS;
        int withdrawAmount = rand() % (MAX_AMOUNT - MIN_AMOUNT + 1) + MIN_AMOUNT;
        accounts[accountIndex].withdraw(withdrawAmount);
        this_thread::sleep_for(chrono::milliseconds(rand() % 1000));
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    BankAccount accounts[NUM_ACCOUNTS];

    thread depositThread1(depositThread, accounts);
    thread depositThread2(depositThread, accounts);
    thread withdrawThread1(withdrawThread, accounts);
    thread withdrawThread2(withdrawThread, accounts);

    depositThread1.join();
    depositThread2.join();
    withdrawThread1.join();
    withdrawThread2.join();

    return 0;
}