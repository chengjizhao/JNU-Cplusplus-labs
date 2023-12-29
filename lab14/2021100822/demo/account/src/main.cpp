#include "account.h"
#include <iostream>
#include <thread>
#include <random>

void randomDepositWithdraw(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < 10; ++i) { 
        int depositAmount = dis(gen);
        account.deposit(depositAmount);
        std::cout << "Deposited: " << depositAmount << " yuan to account " << account.getName() << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        int withdrawAmount = dis(gen);
        account.withdraw(withdrawAmount);
        std::cout << "Withdrawn: " << withdrawAmount << " yuan from account " << account.getName() << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    BankAccount accountA("A", 1000);

    randomDepositWithdraw(accountA); // 执行多次存取

    std::cout << "Account A balance: " << accountA.getBalance() << " yuan." << std::endl;

    return 0;
}