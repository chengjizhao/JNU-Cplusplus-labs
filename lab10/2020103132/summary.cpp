/*总结C++中各种可能的对象的内存模型，并画图解释其原理，
并编程验证，必选包含一般类对象，继承类对象，带虚函数的类对象，
基类有虚函数的子类对象，基类有虚函数且子类有自己的更多的虚函数的
类对象， 多继承的类对象，虚基类的类对象（统一用GCC编译器）。*/

#include<iostream>
using namespace std;

class A//一般类对象
{
public:
    int a;
    int func()const;
};

class A1:public A//继承类
{
    public:
    int funcA1()const;
    int a1;
};

class C//带虚函数的类对象
{
    public:
    virtual void funcC();
    int c;
};

class C1:public class C{};//基类有虚函数的子类对象

class C2:public class C//基类有虚函数且子类有自己的更多的虚函数的类对象
{
    public:
    virtual void funcC2();
    virtual void funcC21();
    int e;
    int e1;
};

class F//多继承
{
    public:
    virtual void funcF();
    virtual void funcF1();
    int f;
};

class F1:virtual public F
{
    pulic:
    virtual void funcF();
    int f1;
};

class F2:virtual public F
{
    public:
    int f2;
};

class FF: public F1,public F2
{
    public:
    int ff;
};


int main()
{
    cout<<sizeof(A)<<endl;
    cout<<sizeof(A1)<<endl;
    cout<<endl;
    cout<<sizeof(C)<<endl;
    cout<<sizeof(C1)<<endl;
    cout<<sizeof(C2)<<endl;
    cout<<endl;
    cout<<sizeof(F)<<endl;
    cout<<sizeof(F1)<<endl;
    cout<<sizeof(F2)<<endl;
    cout<<sizeof(FF)<<endl;
    
    return 0;
}
