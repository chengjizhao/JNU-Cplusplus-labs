/*
定义一个共享的计数器，
创建两个线程，一个线程递增计数器100次，另一个线程递减计数器50次。
使用互斥锁确保对计数器的并发访问是线程安全的。输出最终的计数器值。
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;//计数

mutex mtx;

void increment()//增加函数： 这个函数用于增加计数器的值。
{
    for (int i = 0; i < 100; i++)
    {
        mtx.lock();//锁定互斥锁
        counter++;
        mtx.unlock();//解锁互斥锁
    }
}

void decrement()// 减少函数 这个函数用于减少计数器的值。
{
    for (int i = 0; i < 50; i++)
    {
        mtx.lock();//锁定互斥锁
        counter--;
        mtx.unlock();//解锁互斥锁
    }
}


int main()
{
    cout <<"原计数器的值：" <<counter << endl;
    
    //创建线程递增计数器100次
    thread t1(increment);

    //创建线程递减计数器50次
    thread t2(decrement);

    t1.join();
    t2.join();

    cout <<"现计数器的值：" <<counter << endl;

    return 0;
}

