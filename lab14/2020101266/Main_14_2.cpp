#include <iostream>  
#include <thread>  
#include <mutex>  
#include <condition_variable>  
#include <random>  
#include <chrono>  

class BankAccount {
public:
    BankAccount(int id) : id(id), balance(1000) {}

    void deposit(int amount) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return amount <= balance; }); // �ȴ�����㹻  
        balance += amount;
        std::cout << "Account " << id << " deposit: " << amount << ", balance: " << balance << std::endl;
        lock.unlock();
        cv.notify_one(); // ֪ͨȡ�����  
    }

    void withdraw(int amount) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return amount <= balance; }); // �ȴ�����㹻  
        balance -= amount;
        std::cout << "Account " << id << " withdraw: " << amount << ", balance: " << balance << std::endl;
        lock.unlock();
        cv.notify_one(); // ֪ͨ������������ȡ�����  
    }

private:
    int id;
    int balance;
    std::mutex mtx; // ��������ȷ���̰߳�ȫ  
    std::condition_variable cv; // ���������������߳�ͬ��  
};

void deposit_to_random_account(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd()); // �����������  
    std::uniform_int_distribution<> dis(1, 100); // ȡ�Χ��1Ԫ��100Ԫ֮��  
    for (int i = 0; i < 100; ++i) { // ִ��100�δ�����  
        account.deposit(dis(gen)); // ��������  
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 5 + 1)); // ���ʱ������1���뵽5����֮��  
    }
}

void withdraw_from_random_account(BankAccount& account) {
    std::random_device rd;
    std::mt19937 gen(rd()); // �����������  
    std::uniform_int_distribution<> dis(1, 100); // ȡ�Χ��1Ԫ��100Ԫ֮��  
    for (int i = 0; i < 100; ++i) { // ִ��100��ȡ�����  
        account.withdraw(dis(gen)); // ���ȡ����  
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 5 + 1)); // ���ʱ������1���뵽5����֮��  
    }
}

int main() {
    BankAccount account1(1); // �����˻�1����ʼ���Ϊ1000Ԫ  
    BankAccount account2(2); // �����˻�2����ʼ���Ϊ1000Ԫ��ʵ�ʳ����п��Դ�������˻���  
    std::thread t1(&deposit_to_random_account, std::ref(account1)); // �����߳�ִ�д��������˻�1��  
    std::thread t2(&withdraw_from_random_account, std::ref(account2)); // �����߳�ִ��ȡ��������˻�2��  
    t1.join(); // �ȴ��߳�t1ִ�����  
    t2.join(); // �ȴ��߳�t2ִ�����  
    return 0;
}