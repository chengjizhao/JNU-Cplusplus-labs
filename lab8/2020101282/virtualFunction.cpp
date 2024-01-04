//简单的程序示例，用于说明虚函数的内存结构，包括虚函数表在内存中的位置以及多个不同对象是否指向同一个虚函数表
#include <iostream>

class Base {
public:
    virtual void virtualFunction() {
        std::cout << "Base's virtualFunction()" << std::endl;
    }
};

class Derived : public Base {
public:
    void virtualFunction() override {
        std::cout << "Derived's virtualFunction()" << std::endl;
    }
};

int main() {
    Base base;
    Derived derived;

    // 使用基类指针访问虚函数
    Base* basePtr1 = &base;
    Base* basePtr2 = &derived;

    basePtr1->virtualFunction(); // 调用 Base 的虚函数
    basePtr2->virtualFunction(); // 调用 Derived 的虚函数

    // 检查虚函数表的地址
    void** vtableBase = *(void***)&base;
    void** vtableDerived = *(void***)&derived;

    std::cout << "Address of Base's vtable: " << vtableBase << std::endl;
    std::cout << "Address of Derived's vtable: " << vtableDerived << std::endl;

    return 0;
}
