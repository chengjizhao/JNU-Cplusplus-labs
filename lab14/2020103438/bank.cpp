#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
using namespace std;
class Account
{
public:
    Account(string name)
    {
        this->name = name;
    }
    void withdraw()
    {
        lock_guard<mutex> lock(mtx);
        saving -= rand() % 100 + 1;
        cout << "取钱，当前余额为："  << saving << endl;
    }
    void deposit()
    {
        lock_guard<mutex> lock(mtx);
        saving += rand() % 100 + 1;
        cout << "存钱，当前余额为：" << saving << endl;
    }
    string name;
    int saving = 1000;
    mutex mtx;
};
void withdraw_thread(Account &a)
{
       while (1) 
       {
        if (a.saving >100) 
        {
            a.withdraw();
            this_thread::sleep_for(chrono::milliseconds((rand() % 100 + 1) * 10));
        }
       }
}
void deposit_thread(Account &a)
{
    while (1)
    {   
        a.deposit();
        this_thread::sleep_for(chrono::milliseconds((rand() % 100 + 1) * 10));
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    Account a("chen");
    thread t1(withdraw_thread, ref(a));
    thread t2(deposit_thread, ref(a));

    t1.join();
    t2.join();


}
