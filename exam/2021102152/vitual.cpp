#include<iostream>
class AbstractClass {
public:
    virtual void virtualFunc() { std::cout << "Base virtualFunc" << std::endl; } // 非纯虚函数，有默认实现
    virtual void pureVirtualFunc() = 0; // 纯虚函数，没有实现，也没有默认实现
};
class DerivedClass : public AbstractClass {
public:
    void pureVirtualFunc() override { std::cout << "Derived pureVirtualFunc" << std::endl; } // 重写纯虚函数
};
//AbstractClass是一个抽象类，包含一个非纯虚函数 virtualFunc和一个纯虚函数 pureVirtualFunc。DerivedClass是 AbstractClass的派生类，重写了 pureVirtualFunc。在 DerivedClass的对象中，有一个指向 virtualFunc和 pureVirtualFunc的虚函数表的虚指针。当通过该对象的成员函数指针调用这些函数时，将根据虚函数表查找并调用正确的函数实现，实现多态性。
