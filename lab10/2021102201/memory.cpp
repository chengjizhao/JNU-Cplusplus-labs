#include <iostream>

using namespace std;

class Base1
{
public:
    int base1;

    virtual void base1Func() {
        cout << "Base1::base1Func()" << endl;
    }
};

class Derived1 : public Base1
{
public:
    int derived1;

    virtual void derived1Func()
    {
        cout << "Derived1::derived1Func()" << endl;
    }
};

class Derived2 : public Derived1
{
public:
    int derived2;

    virtual void Derived2Func()
    {
        cout << "Derived2::Derived2Func()" << endl;
    }
};

class Base2
{
public:
    int base2;

    virtual void Base2Func()
    {
        cout << "Base2::Base2Func()" << endl;
    }
};

class MultiInheritance : public Base1, public Base2
{
public:
    int multiInheritance;

    virtual void multiInheritanceFunc()
    {
        cout << "MultiInheritance::multiInheritanceFunc()" << endl;
    }
};

int main()
{
    Base1 base1Obj;
    Derived1 derived2Obj;
    Derived2 Derived2Obj;
    MultiInheritance multiInheritanceObj;

    cout << "Base1的大小为: " << sizeof(base1Obj) << endl;
    cout << "Derived1的大小为: " << sizeof(derived2Obj) << endl;
    cout << "Derived2的大小为: " << sizeof(Derived2Obj) << endl;
    cout << "MultiInheritance的大小为: " << sizeof(multiInheritanceObj) << endl;

    return 0;
}