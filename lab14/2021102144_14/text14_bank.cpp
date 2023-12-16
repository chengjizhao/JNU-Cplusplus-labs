#include <iostream>  
#include <thread>  
#include <mutex>  
#include <random>  
#include <vector>  
using namespace std;
class BankAccount 
{  
public:  
    BankAccount(int initial_balance) : balance(initial_balance) {}  
    // 存款操作  
    void deposit(int amount) 
    {  
        unique_lock<mutex> lock(mtx);  
        balance += amount;  
        cout << "存款 " << amount << ", 新的余额是 " << balance << endl;  
    }  
  
    // 取款操作  
    void withdraw(int amount)
    {  
        unique_lock<mutex> lock(mtx);//确保该代码段只有一个线程在运行  
        if (amount > balance) {  
            cout << "余额不足，无法取款 " << amount << endl;  
            return;  
        }  
        balance -= amount;  
        cout << "取款 " << amount << ", 新的余额是 " << balance << endl;  
    }  
private:  
    int balance;  
    mutex mtx;  
};  
  
void deposit_thread(BankAccount& account, random_device& rd) 
{  
    mt19937 gen(rd());  
    uniform_int_distribution<> dis(1, 100);  
    for (int i = 0; i < 10; ++i) {  
        int amount = dis(gen);  
        account.deposit(amount);  
        this_thread::sleep_for(chrono::milliseconds(1000)); // 随机时间间隔，这里设定为1秒，根据实际需求调整。  
    }  
}  
  
void withdraw_thread(BankAccount& account, random_device& rd) 
{  
    mt19937 gen(rd());  
    uniform_int_distribution<> dis(1, 100);//生成随机数  
    for (int i = 0; i < 10; ++i) {  
        int amount = dis(gen);  
        account.withdraw(amount);  
        this_thread::sleep_for(chrono::milliseconds(2000)); // 随机时间间隔，这里设定为2秒，根据实际需求调整。  
    }  
}  
  
int main() {  
    random_device rd; // 用于生成随机数种子。你可以选择一个更复杂的种子源，例如使用当前时间。  
    BankAccount account(1000); // 初始余额为1000元。可以根据需要调整。  
    thread deposit_t(deposit_thread,ref(account), ref(rd)); // 创建存款线程。你也可以使用其他线程创建方法，例如 std::async。  
    thread withdraw_t(withdraw_thread,ref(account), ref(rd)); // 创建取款线程。你也可以使用其他线程创建方法，例如 std::async。  
    deposit_t.join(); // 等待存款线程完成。你也可以使用其他等待线程完成的方法，例如 std::thread::joinable。  
    withdraw_t.join(); // 等待取款线程完成。你也可以使用其他等待线程完成的方法，例如 std::thread::joinable。  
    return 0;  
}