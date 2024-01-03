#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cstdlib>
#include <ctime>

class BankAccount {
public:
    explicit BankAccount(int initialBalance, int accountNumber) : balance(initialBalance), accountNumber(accountNumber) {}

    // 添加移动构造函数
    BankAccount(BankAccount&& other) noexcept : balance(0), accountNumber(other.accountNumber) {
        std::lock_guard<std::mutex> lock(accountMutex);
        std::swap(balance, other.balance);
    }

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(accountMutex);
        balance += amount;
        std::cout << "账户" << accountNumber << " 存款：" << amount << "，新余额：" << balance << std::endl;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(accountMutex);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "账户" << accountNumber << " 取款：" << amount << "，新余额：" << balance << std::endl;
        } else {
            std::cout << "账户" << accountNumber << " 取款失败，余额不足。" << std::endl;
        }
    }

    int getBalance() const {
        std::lock_guard<std::mutex> lock(accountMutex);
        return balance;
    }

private:
    int balance;
    int accountNumber;
    mutable std::mutex accountMutex;
};

void performTransaction(BankAccount& account, const std::string& operation) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int amount = std::rand() % 100 + 1; // 随机生成1到100之间的金额
    if (operation == "deposit") {
        account.deposit(amount);
    } else if (operation == "withdraw") {
        account.withdraw(amount);
    }
}

void transactionThread(BankAccount& account, const std::string& operation) {
    for (int i = 0; i < 10; ++i) {
        performTransaction(account, operation);
        std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 1000 + 500)); // 随机休眠500ms到1500ms之间的时间
    }
}

int main() {
    std::vector<BankAccount> accounts;

    // 预设五个账户
    for (int i = 0; i < 5; ++i) {
        accounts.emplace_back(1000, i + 1);
    }

    // 显示每个账户的初始余额
    for (size_t i = 0; i < accounts.size(); ++i) {
        std::cout << "账户" << i + 1 << " 初始余额: " << accounts[i].getBalance() << std::endl;
    }

    std::vector<std::thread> threads;

    // 启动多个线程进行存取款操作
    for (size_t i = 0; i < accounts.size(); ++i) {
        threads.emplace_back(transactionThread, std::ref(accounts[i]), "deposit");
        threads.emplace_back(transactionThread, std::ref(accounts[i]), "withdraw");
    }

    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }

    // 显示每个账户的最终余额
    for (size_t i = 0; i < accounts.size(); ++i) {
        std::cout << "账户" << i + 1 << " 最终余额: " << accounts[i].getBalance() << std::endl;
    }

    // 等待用户输入，保持程序运行在最后的余额显示那里
    std::cout << "按 Enter 键退出程序..." << std::endl;
    std::cin.get();

    return 0;
}