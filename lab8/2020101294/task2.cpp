#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Derived class" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    Base* basePtr = &baseObj;
    Base* derivedPtr = &derivedObj;

    // 虚函数调用
    basePtr->print();    // 输出 "Base class"
    derivedPtr->print(); // 输出 "Derived class"

    // 虚函数表地址
    void* baseVTable = *(void**)(&baseObj);
    void* derivedVTable = *(void**)(&derivedObj);

    std::cout << "Base VTable Address: " << baseVTable << std::endl;
    std::cout << "Derived VTable Address: " << derivedVTable << std::endl;

    return 0;
}