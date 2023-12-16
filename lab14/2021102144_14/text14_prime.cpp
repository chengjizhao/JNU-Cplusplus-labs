#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;
vector<int>v1;
bool isPrime(int n) 
{
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}
void Pull(int n)
{
mutex mtx;
mtx.lock();
v1.push_back(n);
mtx.unlock();
}
int main()
{   
    const int num=100;
    for(int i=0;i<num;i++)
    {
    if(isPrime(i))
    {
    thread t1(Pull,i);
    t1.join();
    }
    }
    for(int i=1; i <v1.size();i++) 
        {
        cout<<v1[i]<<" ";
        if(i%3==0)
        cout<<endl;
        }  
    return 0;
}