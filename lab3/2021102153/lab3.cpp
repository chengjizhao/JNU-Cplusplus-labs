#include<vector>
#include<list>
#include<stdlib.h>//随机数函数
#include<algorithm>//find函数
#include <chrono>  // 用于计时
#include <ctime>  // 用于获取当前时间
#include<iostream>
using namespace std;
int count(int a);
int num[1001]={0};
int main()
{   
    for(int i=1;i<=1001;i++){
        count(i);
    }
    cout<<"忧伤的数：";
    for(int i=1;i<=1001;i++){
        if(num[i])cout<<i<<" ";
    }
    cout<<endl;
    cout<<"幸福的数: ";
    for(int i=1;i<=1001;i++){
        if(!num[i])cout<<i<<" ";
    }
}

int count(int a)
{
if(a==1)
{
    num[1]=1;
    return 1;
    }
if(num[a]==-2)
{
    return 0;
}
num[a]=-2;
int c[100]={0};
int t[1000]={0};
int ts=0;
int i1;
int a1=a;
for(int i=0;;i++)
{
    c[i]=a%10;
    a=a/10;
    if(a==0)
    {
        i1=i+1;
        break;
    }
}

for(int j=0;j<i1;j++)
{
ts+=c[j]*c[j];
}
    num[a1]=count(ts);
    return num[a1];
}
