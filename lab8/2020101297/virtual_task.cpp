#include <iostream>

class Base {
public:
    virtual void func() {
        std::cout << "Base::func()" << std::endl;
    }
};

class Derived : public Base {
public:
    virtual void func() {
        std::cout << "Derived::func()" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    Base* pBase = &baseObj;
    Derived* pDerived = &derivedObj;

    // 输出虚函数表的地址
    std::cout << "Base::func() vtable address: " << reinterpret_cast<void*>(*(reinterpret_cast<void**>(&baseObj))) << std::endl;
    std::cout << "Derived::func() vtable address: " << reinterpret_cast<void*>(*(reinterpret_cast<void**>(&derivedObj))) << std::endl;

    // 调用虚函数
    pBase->func();
    pDerived->func();

    return 0;
}
