#include "lab6.h"
void test::privatemethods()
{
    cout << "privatemethods" << endl;
}

void test::methods()
{
    this->privatemethods();
}

void methods1(test &a)
{
    a.privatemethods();
}

void test1::methods2(test &a)
    {
        a.privatemethods();
    }
int main()
{
    test a;
    test1 a1;
    // auto s=&test::privatemethods;
    // 无法通过私有成员函数的指针付给一个外部函数指针的方式调用私有成员函数因为无法获取私有成员函数指针
    a.methods();//通过公有成员函数调用私有成员函数
    methods1(a);//全局函数做友元
    a1.methods2(a);//成员函数做友元
}

