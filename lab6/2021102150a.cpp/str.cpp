#include<iostream>
#include<string>
using namespace std;

class Time
{
private:
    int hour;
    int min;
public:
    Time(int a,int b){
        hour=a;min=b;
    }
    int ad(Time &t);
    int (*fun)(Time &t)=ad;
    friend int AD(Time &t);
};

int AD(Time &t){//使用友元函数访问private成员
    return t.hour+t.min;
}

int Time::ad(Time &t){
    return t.hour+t.min;
}

int main(){
    Time t(3,30);
    int (*p)(Time &t);
    //int *p,*q;
    //p=&t.hour;//若直接定义指针则无法调用
    //q=&t.min;
    cout<<AD(t)<<endl;
    cout<<t.fun(t)<<endl;
}