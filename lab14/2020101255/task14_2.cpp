#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <random>
#include <chrono>
#include <string>

using namespace std;

class BankAccount
{
    public:
        BankAccount(int initialBalance, string _name) : balance(initialBalance), name(_name) {}

        void deposit(int amount)
        {
            lock_guard<mutex> lock(mtx);
            balance += amount;
            cout << name << " Deposit: " << amount << ", New balance: " << balance << endl;
        }

        void withdraw(int amount)
        {
            lock_guard<mutex> lock(mtx);
            if (balance >= amount)
            {
                balance -= amount;
                cout << name << " Withdraw: " << amount << ", New balance: " << balance << endl;
            }
            else
            {
                cout << name << " Insufficient funds for withdrawal of " << amount << endl;
            }
        }

    private:
        int balance;
        mutex mtx;
        string name;
};

int random_num()
{
    auto now = std::chrono::system_clock::now();
    auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    return timestamp % 100 + 1;
}

void randomDeposit(BankAccount& account)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> intervalDistribution(500, 1000);

    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(intervalDistribution(gen)));
        int amount = random_num();
        account.deposit(amount);
    }
}

void randomWithdraw(BankAccount& account)
{
    random_device rd1;
    mt19937 gen1(rd1());
    uniform_int_distribution<int> intervalDistribution(500, 1000);

    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(intervalDistribution(gen1)));
        int amount = random_num();
        account.withdraw(amount);
    }
}

int main()
{

    BankAccount account1(1000, "A1");
    BankAccount account2(1000, "A2");

    thread depositThread1(randomDeposit, ref(account1));
    thread withdrawThread1(randomWithdraw, ref(account1));
    thread depositThread2(randomDeposit, ref(account2));
    thread withdrawThread2(randomWithdraw, ref(account2));

    depositThread1.join();
    withdrawThread1.join();
    depositThread2.join();
    withdrawThread2.join();

    return 0;
}
