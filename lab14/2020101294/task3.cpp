#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cstdlib>
#include <ctime>

class BankAccount {
public:
    explicit BankAccount(int initialBalance, int accountNumber) : balance(initialBalance), accountNumber(accountNumber) {}

    // ����ƶ����캯��
    BankAccount(BankAccount&& other) noexcept : balance(0), accountNumber(other.accountNumber) {
        std::lock_guard<std::mutex> lock(accountMutex);
        std::swap(balance, other.balance);
    }

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(accountMutex);
        balance += amount;
        std::cout << "�˻�" << accountNumber << " ��" << amount << "������" << balance << std::endl;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(accountMutex);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "�˻�" << accountNumber << " ȡ�" << amount << "������" << balance << std::endl;
        } else {
            std::cout << "�˻�" << accountNumber << " ȡ��ʧ�ܣ����㡣" << std::endl;
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
    int amount = std::rand() % 100 + 1; // �������1��100֮��Ľ��
    if (operation == "deposit") {
        account.deposit(amount);
    } else if (operation == "withdraw") {
        account.withdraw(amount);
    }
}

void transactionThread(BankAccount& account, const std::string& operation) {
    for (int i = 0; i < 10; ++i) {
        performTransaction(account, operation);
        std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 1000 + 500)); // �������500ms��1500ms֮���ʱ��
    }
}

int main() {
    std::vector<BankAccount> accounts;

    // Ԥ������˻�
    for (int i = 0; i < 5; ++i) {
        accounts.emplace_back(1000, i + 1);
    }

    // ��ʾÿ���˻��ĳ�ʼ���
    for (size_t i = 0; i < accounts.size(); ++i) {
        std::cout << "�˻�" << i + 1 << " ��ʼ���: " << accounts[i].getBalance() << std::endl;
    }

    std::vector<std::thread> threads;

    // ��������߳̽��д�ȡ�����
    for (size_t i = 0; i < accounts.size(); ++i) {
        threads.emplace_back(transactionThread, std::ref(accounts[i]), "deposit");
        threads.emplace_back(transactionThread, std::ref(accounts[i]), "withdraw");
    }

    // �ȴ������߳����
    for (auto& thread : threads) {
        thread.join();
    }

    // ��ʾÿ���˻����������
    for (size_t i = 0; i < accounts.size(); ++i) {
        std::cout << "�˻�" << i + 1 << " �������: " << accounts[i].getBalance() << std::endl;
    }

    // �ȴ��û����룬���ֳ������������������ʾ����
    std::cout << "�� Enter ���˳�����..." << std::endl;
    std::cin.get();

    return 0;
}