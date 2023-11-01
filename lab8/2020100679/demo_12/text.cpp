#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "Base::print()" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Derived::print()" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    Base* basePtr1 = &baseObj;
    Base* basePtr2 = &derivedObj;

    basePtr1->print();  // 输出：Base::print()
    basePtr2->print();  // 输出：Derived::print()

    return 0;
}
