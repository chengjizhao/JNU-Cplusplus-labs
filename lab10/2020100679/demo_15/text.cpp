#include <iostream>
using namespace std;

class Base {
public:
    int baseVar;

    virtual void baseFunc() {
        cout << "Base::baseFunc()" << endl;
    }
};

class Derived : public Base {
public:
    int derivedVar;

    void derivedFunc() {
        cout << "Derived::derivedFunc()" << endl;
    }
};

class WithVirtualFunc {
public:
    int var;

    virtual void virtualFunc() {
        cout << "WithVirtualFunc::virtualFunc()" << endl;
    }
};

class DerivedWithMoreVirtualFunc : public Base, public WithVirtualFunc {
public:
    int derivedVar;

    void derivedFunc() {
        cout << "DerivedWithMoreVirtualFunc::derivedFunc()" << endl;
    }

    void virtualFunc() override {
        cout << "DerivedWithMoreVirtualFunc::virtualFunc()" << endl;
    }
};

int main() {
    // 一般类对象
    cout << "Size of Base: " << sizeof(Base) << endl;

    // 继承类对象
    cout << "Size of Derived: " << sizeof(Derived) << endl;

    // 带虚函数的类对象
    cout << "Size of WithVirtualFunc: " << sizeof(WithVirtualFunc) << endl;

    // 基类有虚函数的子类对象
    cout << "Size of DerivedWithMoreVirtualFunc: " << sizeof(DerivedWithMoreVirtualFunc) << endl;

    // 多继的类对象
    class MultipleInheritance : public Base, public WithVirtualFunc {
    public:
        int var;
    };

    cout << "Size of MultipleInheritance: " << sizeof(MultipleInheritance) << endl;

    // 虚基类的类对象
    class VirtualBase {
    public:
        int baseVar;
    };

    class DerivedWithVirtualBase : public virtual VirtualBase {
    public:
        int derivedVar;
    };

    cout << "Size of DerivedWithVirtualBase: " << sizeof(DerivedWithVirtualBase) << endl;

    return 0;
}
