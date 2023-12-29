#include "account.h"
#include <iostream>

BankAccount::BankAccount(const std::string& name, double initialBalance) : mName(name), mBalance(initialBalance) {}

void BankAccount::deposit(double amount) {
    std::lock_guard<std::mutex> lock(mMutex);  // 用互斥锁对象构造 lock_guard
    mBalance += amount;
}

void BankAccount::withdraw(double amount) {
    std::lock_guard<std::mutex> lock(mMutex);  // 用互斥锁对象构造 lock_guard
    if (mBalance >= amount) {
        mBalance -= amount;
    }
    else {
        std::cout << "Insufficient funds" << std::endl;
    }
}

double BankAccount::getBalance() const {
    std::lock_guard<std::mutex> lock(mMutex);  // 用互斥锁对象构造 lock_guard
    return mBalance;
}

std::string BankAccount::getName() const {
    return mName;
}