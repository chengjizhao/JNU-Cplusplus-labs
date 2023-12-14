#include <iostream>  
#include <thread>  
#include <mutex>  
#include <condition_variable>
#include <random>

using namespace std;

#define accountNum 10   //账户数量
#define cycleTimes 10   //存取钱循环次数

mutex printlock;
condition_variable print_cond;
bool print_flag = false;

class BankAccount
{
private:
    mutex mutex_;
    //condition_variable deposit_cond;  存钱时不需考虑钱不够的情况
    condition_variable withdraw_cond;

public:
    int money = 1000;

    void deposit(int amount, int actNO)
    {
        unique_lock<mutex> lock(mutex_);
        money += amount;
        //cout << "Account " << (actNO+1) << " " << "has deposited: " << amount << " ,Now have: " << money << endl;
    }

    void withdraw(int amount, int actNO)
    {
        unique_lock<mutex> lock(mutex_);
        withdraw_cond.wait(lock,[this, amount](){return money>=amount;});
        money -= amount;
        //cout << "Account " << (actNO+1) << " " << "has Withdrawn: " << amount << " ,Now have: " << money << endl;
    }
};

/*
*   函数名称:   int random_Num(int min, int max)
*   输入变量:   int min, int max
*   返回变量:   dis(gen);
*   功能简介:   输入上下界,并返回界内的一个随机整数
*/
int random_Num(int min, int max)
{
    random_device rd;  
    mt19937 gen(rd());  
    uniform_int_distribution<> dis(min, max);  
    // 生成随机数并返回  
    return dis(gen);  
}

/*
*   函数名称:   void deposit_Thread(BankAccount* act)
*   输入变量:   BankAccount* act
*   返回变量:   NULL
*   功能简介:   存钱线程功能函数
*/
void deposit_Thread(BankAccount* act)
{
    for(int i=0; i<cycleTimes; i++)
    {
        int sleep_time = random_Num(1,100);
        this_thread::sleep_for(std::chrono::milliseconds(sleep_time));

        int act_NO = random_Num(0,accountNum-1);
        int money_amout = random_Num(1,100);
        act[act_NO].deposit(money_amout, act_NO);
        
        {
            //unique_lock<mutex> lock(printlock);
            //print_cond.wait(lock,[](){return !print_flag;});
            cout << "Thread 1 sleep: " << sleep_time << " ms. $$ ";
            cout << "Account " << (act_NO+1) << " " << "has deposited: " << money_amout << " ,Now have: " << act[act_NO].money << endl;
            //print_flag = true;
        }
        
    }
    
}

/*
*   函数名称:   void withdraw_Thread(BankAccount* act)
*   输入变量:   BankAccount* act
*   返回变量:   NULL
*   功能简介:   取钱线程功能函数
*/
void withdraw_Thread(BankAccount* act)
{
    for(int i=0; i<cycleTimes; i++)
    {
        int sleep_time = random_Num(1,100);
        this_thread::sleep_for(std::chrono::milliseconds(sleep_time));    //休眠

        int act_NO = random_Num(0,accountNum-1);
        int money_amout = random_Num(1,100);
        act[act_NO].withdraw(money_amout, act_NO);

        {
            //unique_lock<mutex> lock(printlock);
            //print_cond.wait(lock,[](){return print_flag;});
            cout << "Thread 2 sleep: " << sleep_time << " ms. $$ ";
            cout << "Account " << (act_NO+1) << " " << "has Withdrawn: " << money_amout << " ,Now have: " << act[act_NO].money << endl;
            //print_flag = false;
        }
    }
}

//主函数
int main()
{
    BankAccount Account[accountNum];    //创建账户
    thread deposit_thread(deposit_Thread, Account);     //创建线程
    thread withdraw_thread(withdraw_Thread, Account);
    deposit_thread.join(); 
    withdraw_thread.join();
    return 0;
}