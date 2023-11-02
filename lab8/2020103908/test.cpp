#include <iostream>

class Base {
public:
    virtual void virtualFunction() {
        std::cout << "Base::virtualFunction" << std::endl;
    }
};

class Derived : public Base {
public:
    void virtualFunction() override {
        std::cout << "Derived::virtualFunction" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    Base* basePtr = &baseObj;
    Base* derivedPtr = &derivedObj;

    // 输出对象的虚函数地址
    std::cout << "Address of Base object's vtable: " << reinterpret_cast<void*>(basePtr) << std::endl;
    std::cout << "Address of Derived object's vtable: " << reinterpret_cast<void*>(derivedPtr) << std::endl;

    // 调用虚函数
    basePtr->virtualFunction();
    derivedPtr->virtualFunction();

    return 0;
}
