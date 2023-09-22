#include<vector>
#include<list>
#include<stdlib.h>//随机数函数
#include<algorithm>//find函数
#include <chrono>  // 用于计时
#include <ctime>  // 用于获取当前时间
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{   vector<int> s(100000);
    list<int> s1;
    list<int>::iterator w[100000];
    srand(1);
    DWORD Start = GetTickCount();
    for(int i=0;i<99999;i++)
    {   int a=rand()%99999;//范围
        int b=rand()%99999;
        s.insert(s.begin()+a,b);
    }
    DWORD End =GetTickCount();
    cout << "vector程序运行时间为" << (End-Start) << "ms" <<endl;
        for(int i=0;i<=100000;i++){
        int a=rand()%99999;//范围
        w[i] = find(s1.begin(),s1.end(),a);
    }
    DWORD Starts = GetTickCount();
    for(int i=0;i<99999;i++)
    {
        int b=rand()%99999;
        s1.insert(w[i],b);
    }
    DWORD Ends =GetTickCount();
    auto t=Ends-Starts;
    cout << "list程序运行时间为" << t << "ms" <<endl;


}