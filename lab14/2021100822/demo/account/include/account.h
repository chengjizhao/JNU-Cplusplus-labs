#pragma once

#include <string>
#include <mutex>

class BankAccount {
public:
    BankAccount(const std::string& name, double initialBalance);

    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    std::string getName() const;

private:
    std::string mName;
    double mBalance;
    mutable std::mutex mMutex;  // mutable 关键字的作用是允许在 const 成员函数中修改该成员变量
};