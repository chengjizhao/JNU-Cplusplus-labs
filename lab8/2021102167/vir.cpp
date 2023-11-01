#include <iostream>

using namespace std;

class Base {
public:
    virtual void func() {
        cout << "Base::func()" << endl;
    }
};

class Derived : public Base {
public:
    virtual void func() {
        cout << "Derived::func()" << endl;
    }
};

int main() {
    Base* b = new Derived();
    b->func();
    delete b;
    return 0;
}