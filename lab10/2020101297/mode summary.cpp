#include <iostream>
using namespace std;

class Base {
public:
    int baseVar;
    virtual void baseFunc() {}
};

class Derived : public Base {
public:
    int derivedVar;
    virtual void derivedFunc() {}
};

class AnotherDerived : public Base {
public:
    int anotherDerivedVar;
    virtual void anotherDerivedFunc() {}
};

int main() {
    // 一般类对象
    cout << "Size of Base: " << sizeof(Base) << endl;

    // 继承类对象
    cout << "Size of Derived: " << sizeof(Derived) << endl;

    // 带虚函数的类对象
    cout << "Size of Base with virtual function: " << sizeof(Base) << endl;

    // 基类有虚函数的子类对象
    cout << "Size of Derived with base virtual function: " << sizeof(Derived) << endl;

    // 基类有虚函数且子类有自己的更多虚函数的类对象
    cout << "Size of AnotherDerived with additional virtual function: " << sizeof(AnotherDerived) << endl;

    // 多继承的类对象
    class MultipleInheritance : public Derived, public AnotherDerived {
    public:
        int multipleVar;
    };
    cout << "Size of MultipleInheritance: " << sizeof(MultipleInheritance) << endl;

    // 虚基类的类对象
    class VirtualBase : virtual public Base {
    public:
        int virtualBaseVar;
    };
    cout << "Size of VirtualBase: " << sizeof(VirtualBase) << endl;
    
    return 0;
}
