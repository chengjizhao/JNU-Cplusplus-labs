//纯虚函数是在基类中声明的没有实现的虚函数。它通过在函数声明的末尾使用 "=0" 来标记。抽象类是包含至少一个纯虚函数的类，它不能被实例化，只能被用作其他类的基类。
//虚函数表是一个用于存储虚函数地址的数据结构，它是在包含虚函数的类的对象中创建的。每个对象都有一个指向虚函数表的虚指针，该指针指向类的虚函数表。通过虚指针，可以在运行时动态地调用适当的虚函数。
//下面通过一个包含纯虚函数的抽象类示例，说明它的虚函数表和虚指针的情况。
#include <iostream>
class AbstractClass {
public:
 virtual void pureVirtualFunction() const =0;
 virtual void virtualFunction() const {
 std::cout << "AbstractClass::virtualFunction()" << std::endl;
 }
};

class ConcreteClass : public AbstractClass {
public:
 void pureVirtualFunction() const override {
 std::cout << "ConcreteClass::pureVirtualFunction()" << std::endl;
 }
};

int main() {
 ConcreteClass concreteObj;
 concreteObj.pureVirtualFunction();
 concreteObj.virtualFunction();

 AbstractClass* abstractPtr = &concreteObj;
 abstractPtr->pureVirtualFunction();
 abstractPtr->virtualFunction();

 return 0;
}

//纯虚函数不能实例化的原因是纯虚函数在类的vftable表中对应的表项被赋值为0。也就是指向一个不存在的函数。由于编译器绝对不允许有调用一个不存在的函数的可能，所以该类不能生成对象。在它的派生类中，除非重写此函数，否则也不能生成对象。
