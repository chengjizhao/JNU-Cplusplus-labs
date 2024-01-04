#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;
int sum=0;
void Pull()
{
mutex mtx;
mtx.lock();
sum+=1;
mtx.unlock();
}
void Push()
{
mutex mtx;
mtx.lock();
sum-=1;
mtx.unlock();
}
int main()
{   
    const int num=100;
    for(int i=0,j=0;i<num;i++,j++)
    {
    thread t1(Pull);
    t1.join();
    if(j<=50)
    {
        thread t2(Push);
        t2.join();
    }
    }
    cout<<sum<<endl;
}