#include "use_class.h"
#include <iostream>
#include <string>
using namespace std;

Person p1;
Person p2;

// 不同初始化方法函数
void setp1();
void setp2();
// 解释位数
void exp();

int main()
{
    /*四种初始化*/
    setp1(); // 初始化一
    setp2(); // 初始化二
    // 初始化三
    Person p3("lyx", "boy", "44xxx520030105xxxx", 2003, 01, 05, 175, 70);
    // 初始化四
    Person p4;
    /*查询*/
    p1.search();
    p2.search();
    p3.search();
    p4.search();
    /*打印所占空间*/
    p2.size(p2);
    /*解释*/
    exp();
    return 0;
}

void setp1()
{
    p1.set();
}

void setp2()
{
    p2.name_ = "lyx";
    p2.set2(p2);
}

void exp()
{
    cout << endl;
    cout << "因为string为32字节，int为4字节，double为字节。" << endl;
}