//当函数里存在虚函数时，编译器为类提供一个指向虚函数表的指针，并通过该指针调用虚函数。
#include<iostream>
#include <stdlib.h>
using namespace std ;

class A
{
    public:
    virtual void function1()
    {cout << "function1" << endl ;}
};

class B :public A//子类的虚函数表前面的函数为继承自父类的函数，后面的为自己的虚函数。
{
    public:
    virtual void function1()
    {cout << "class B function1" << endl ;}
    virtual void function2()
    {cout << "class B function2" << endl ;}
};

typedef void (*Fun)(void);
int main()
{
    B a ;
    cout << (int*)*(int*)&a << endl;
    Fun func=(Fun)*(int*)*(int*)&a;
    func();
    Fun func=((Fun)*(int*)*(int*)&a+1);
    func();
}