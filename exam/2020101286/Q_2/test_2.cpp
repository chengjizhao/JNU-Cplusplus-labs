#include <iostream>
using namespace std;

class Base {
public:
    virtual void fun1() { cout << "Base::fun1" << endl; }
    virtual void fun2() { cout << "Base::fun2" << endl; }
};

class Derived : public Base {
public:
    void fun1() override { cout << "Derived::fun1" << endl; }
    void fun2() override { cout << "Derived::fun2" << endl; }
};

int main() {
    Base* base = new Base();
    Derived* derived = new Derived();

    void** vptrBase = *(void***)base;
    void** vptrDerived = *(void***)derived;

    *(void***)base = vptrDerived;

    base->fun1(); 
    base->fun2();

    *(void***)base = vptrBase;

    delete base;
    delete derived;

    return 0;
}