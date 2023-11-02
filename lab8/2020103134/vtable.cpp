#include<iostream>
using namespace std;

class base
{
    public:
    virtual void fun1()
    {
        cout<<"base virtual function1"<<endl;
    }
    virtual void fun2()
    {
        cout<<"base virtual function2"<<endl;
    }
};

class child:public base
{
    public:
    void fun1() override
    {
        cout<<"child virtual function1"<<endl;
    }
};

int main()
{
    base obj1;
    void (base::*p1)(int)=&base::fun1;
    cout<<"base fun1 address:"<<reinterpret_cast<void*>(p1)<<endl;
    (obj1.fun1)();

    base obj2;
    void (base::*p2)(int)=&base::fun2;
    cout<<"base fun2 address:"<<reinterpret_cast<void*>(p2)<<endl;
    (obj2.fun2)();

    child obj3;
    void (child::*p3)(int)=&child::fun1;
    cout<<"child fun1 address:"<<reinterpret_cast<void*>(p3)<<endl;
    (obj3.fun1)();

    return 0;
}