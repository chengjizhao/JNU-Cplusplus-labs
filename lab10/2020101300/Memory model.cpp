/*1.普通类对象： 一个普通类对象包含其成员变量的内存布局，按照它们在类中的声明顺序排列。

2.继承类对象： 派生类对象包含基类对象的内存布局，并在其之上添加派生类特有的成员变量。

3.带虚函数的类对象： 包含一个指向虚函数表（vtable）的指针，该表包含了虚函数的地址。虚函数表位于对象内存布局的前部。

4.基类有虚函数的子类对象： 同样包含虚函数表指针，同时还有基类的成员变量和派生类的成员变量。

5.基类有虚函数且子类有自己的更多虚函数的类对象： 在虚函数表中包含基类和派生类各自的虚函数地址，同时包含成员变量。

6.多继承的类对象： 对象中包含各个基类的内存布局，根据它们在派生类中的声明顺序排列。

7.虚基类的类对象： 包含一个虚基类指针，指向虚基类的实例。这样可以解决由多继承导致的菱形继承问题。*/
#include <iostream>

//普通类对象
class SimpleClass {
public:
    int data;
};

//继承类对象
class BaseClass {
public:
    int baseData;
};

class DerivedClass : public BaseClass {
public:
    int derivedData;
};

//带虚函数的类对象
class VirtualFunctionClass {
public:
    virtual void virtualFunction() {}
    int data;
};

//基类有虚函数的子类对象
class BaseWithVirtual {
public:
    virtual void virtualFunction() {}
    int baseData;
};

class DerivedWithVirtual : public BaseWithVirtual {
public:
    int derivedData;
};

//基类有虚函数且子类有更多虚函数的类对象
class MoreDerivedWithVirtual : public BaseWithVirtual {
public:
    virtual void anotherVirtualFunction() {}
    int moreDerivedData;
};

class MultipleInheritance : public BaseClass, public VirtualFunctionClass {
public:
    int derivedData;
};

//多继承的类对象
class VirtualBase {
public:
    int virtualBaseData;
};

//虚基类的类对象
class DiamondDerived : virtual public VirtualBase {
public:
    int diamondDerivedData;
};

int main() {
    //在这里创建对象并验证其内存布局
    SimpleClass simpleObj;
    DerivedClass derivedObj;
    VirtualFunctionClass virtualObj;
    DerivedWithVirtual derivedWithVirtualObj;
    MoreDerivedWithVirtual moreDerivedWithVirtualObj;
    MultipleInheritance multipleInheritanceObj;
    DiamondDerived diamondDerivedObj;

    //输出对象的大小
    std::cout << "Size of SimpleClass: "<<sizeof(simpleObj) << " bytes\n";
    std::cout << "Size of DerivedClass: " <<sizeof(derivedObj) << " bytes\n";
    std::cout << "Size of VirtualFunctionClass: " <<sizeof(virtualObj) << " bytes\n";
    std::cout << "Size of DerivedWithVirtual: " <<sizeof(derivedWithVirtualObj) << " bytes\n";
    std::cout << "Size of MoreDerivedWithVirtual: " <<sizeof(moreDerivedWithVirtualObj) << " bytes\n";
    std::cout << "Size of MultipleInheritance: " <<sizeof(multipleInheritanceObj) << " bytes\n";
    std::cout << "Size of DiamondDerived: " <<sizeof(diamondDerivedObj) << " bytes\n";

    return 0;
}