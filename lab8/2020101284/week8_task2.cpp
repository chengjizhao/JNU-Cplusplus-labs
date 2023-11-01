#include <iostream>

class Base {
public:
    virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived : public Base {
public:
    void foo() override {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    Base* basePtr = &baseObj;
    Base* derivedPtr = &derivedObj;

    std::cout << "basePtr's vtable address: " << *((void**)basePtr) << std::endl;
    std::cout << "derivedPtr's vtable address: " << *((void**)derivedPtr) << std::endl;

    return 0;
}