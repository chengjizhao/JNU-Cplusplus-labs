#ifndef _LAB6_H_
#define _LAB6_H_
#include<iostream>
using namespace std;
class test;//前置定义

class test1
{  public:

    void methods2(test &a);
};

class test
{
    public:
    void methods();//直接调用
    friend void methods1(test &a);//全局函数做友元
    friend void test1::methods2(test &a);//成员函数做友元
    private:
    void privatemethods();
    int a=5;
    int b=4;
};

#endif