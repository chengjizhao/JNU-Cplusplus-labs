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
    cout << "Size of Base: " << sizeof(Base) << endl;
    cout << "Size of Derived: " << sizeof(Derived) << endl;
    cout << "Size of Base with virtual function: " << sizeof(Base) << endl;
    cout << "Size of Derived with base virtual function: " << sizeof(Derived) << endl;
    cout << "Size of AnotherDerived with additional virtual function: " << sizeof(AnotherDerived) << endl;
    class MultipleInheritance : public Derived, public AnotherDerived {
    public:
        int multipleVar;
    };
    cout << "Size of MultipleInheritance: " << sizeof(MultipleInheritance) << endl;
    class VirtualBase : virtual public Base {
    public:
        int virtualBaseVar;
    };
    cout << "Size of VirtualBase: " << sizeof(VirtualBase) << endl;
    return 0;
}