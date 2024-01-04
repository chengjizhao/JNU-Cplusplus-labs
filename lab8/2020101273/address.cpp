/*调研虚函数实现的内存结构，包括虚函数表在内存中的位置，多个不同对象是否指向同一个表等课程里面讲解的内容，并编写程序证明你调研的结果的正确性
虚函数实现的内存结构主要包括虚函数表（VTable）和虚函数指针（Virtual Function Pointer，VFP）。
虚函数表是一个包含虚函数地址的数组，用于实现多态。虚函数指针是一个指向虚函数表的指针，存储在类的对象内存布局中。
虚函数表在内存中的位置：虚函数表指针通常存储在类对象内存布局的最前面。
在单一继承情况下，子类会覆盖父类的虚函数表指针，使其指向子类的虚函数表。
多个不同对象是否指向同一个表：是的，多个不同对象的虚函数指针都指向同一个虚函数表。
这是因为虚函数表是共享的，所有具有相同基类的对象都共享同一个虚函数表。*/



#include <iostream>
#include <cstring>

class Base {
public:
    virtual void print() {
        std::cout << "Base::print()" << std::endl;
    }
};

class Derived1 : public Base {
public:
    void print() override {
        std::cout << "Derived1::print()" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void print() override {
        std::cout << "Derived2::print()" << std::endl;
    }
};

int main() {
    Base* basePtr = new Base();
    Derived1* derived1Ptr = new Derived1();
    Derived2* derived2Ptr = new Derived2();

    void (Base::*bPtr)() = &Base::print;
    std::cout << "Memberj0:" << reinterpret_cast<void*>(bPtr) << std::endl;

    void (Derived1::*der1Ptr)() = &Derived1::print;
    std::cout << "Memberj1:" << reinterpret_cast<void*>(der1Ptr) << std::endl;

    void (Derived2::*der2Ptr)() = &Derived2::print;
    std::cout << "Memberj2:" << reinterpret_cast<void*>(der2Ptr) << std::endl;

    if(reinterpret_cast<void*>(bPtr) == reinterpret_cast<void*>(der1Ptr) && \
    reinterpret_cast<void*>(der1Ptr) == reinterpret_cast<void*>(der2Ptr))
    {
        std::cout << "多个不同对象指向的地址一致即同一个表";
    }
    else{
        std::cout<< "no";
    }

    // 释放内存
    delete basePtr;
    delete derived1Ptr;
    delete derived2Ptr;

    return 0;
}