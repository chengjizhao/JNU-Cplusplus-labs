#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cmath>
using namespace std;
#define thread_num  4
mutex mtx;
bool is_prime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
void find_prime(int min, int max, vector<int>& v)
{
    for (int i = min; i <= max; i++)
    {
        if (is_prime(i))
        {
            lock_guard<mutex> lock(mtx);
            v.push_back(i);
        }
    }
}

int main()
{
    int min, max;
    int range;
    vector<int> v;

    cout << "输入查找最小值" << endl;
    cin >> min;
    cout << "输入查找最大值" << endl;
    cin >> max;
    range = (max - min + 1) / thread_num;

    thread t[thread_num];
    for (int i = 0; i < thread_num; i++)
    {
        int begin = min + range * i;
        int end = begin + range - 1;
        t[i] = thread(find_prime, begin, end, ref(v));
    }

    for (int i = 0; i < thread_num; i++)
    {
        t[i].join();
    }
    cout << "查找的素数为：" << endl;
    for(auto it = v.begin(); it != v.end(); it++)
    {  
        cout << *it << "\t" ;
    }
    cout << endl;
    return 0;
}
