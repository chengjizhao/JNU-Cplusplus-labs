#include <iostream>

// 一般类对象
class NormalClass {
public:
    int data;

    NormalClass(int value) : data(value) {}
};

// 继承类对象
class Base {
public:
    int baseData;

    Base(int value) : baseData(value) {}
};

class Derived : public Base {
public:
    int derivedData;

    Derived(int baseValue, int derivedValue) : Base(baseValue), derivedData(derivedValue) {}
};

// 带虚函数的类对象
class VirtualClass {
public:
    int data;

    VirtualClass(int value) : data(value) {}

    virtual void virtualFunction() {
        std::cout << "VirtualClass virtual function" << std::endl;
    }
};

// 基类有虚函数的子类对象
class BaseWithVirtual {
public:
    int baseData;

    BaseWithVirtual(int value) : baseData(value) {}

    virtual void virtualFunction() {
        std::cout << "BaseWithVirtual virtual function" << std::endl;
    }
};

class DerivedWithVirtual : public BaseWithVirtual {
public:
    int derivedData;

    DerivedWithVirtual(int baseValue, int derivedValue) : BaseWithVirtual(baseValue), derivedData(derivedValue) {}

    void virtualFunction() override {
        std::cout << "DerivedWithVirtual virtual function" << std::endl;
    }
};

// 基类有虚函数且子类有更多虚函数的类对象
class BaseWithMoreVirtual {
public:
    int baseData;

    BaseWithMoreVirtual(int value) : baseData(value) {}

    virtual void virtualFunction() {
        std::cout << "BaseWithMoreVirtual virtual function" << std::endl;
    }
};

class DerivedWithMoreVirtual : public BaseWithMoreVirtual {
public:
    int derivedData;

    DerivedWithMoreVirtual(int baseValue, int derivedValue) : BaseWithMoreVirtual(baseValue), derivedData(derivedValue) {}

    void virtualFunction() override {
        std::cout << "DerivedWithMoreVirtual virtual function" << std::endl;
    }

    void additionalVirtualFunction() {
        std::cout << "DerivedWithMoreVirtual additional virtual function" << std::endl;
    }
};

// 多继承的类对象
class Base1 {
public:
    int baseData1;

    Base1(int value) : baseData1(value) {}
};

class Base2 {
public:
    int baseData2;

    Base2(int value) : baseData2(value) {}
};

class MultipleInheritance : public Base1, public Base2 {
public:
    int derivedData;

    MultipleInheritance(int base1Value, int base2Value, int derivedValue)
        : Base1(base1Value), Base2(base2Value), derivedData(derivedValue) {}
};

// 虚基类的类对象
class VirtualBase {
public:
    int data;

    VirtualBase(int value) : data(value) {}
};

class Derived1 : virtual public VirtualBase {
public:
    int derivedData1;

    Derived1(int baseValue, int derivedValue) : VirtualBase(baseValue), derivedData1(derivedValue) {}
};

class Derived2 : virtual public VirtualBase {
public:
    int derivedData2;

    Derived2(int baseValue, int derivedValue) : VirtualBase(baseValue), derivedData2(derivedValue) {}
};

class DiamondInheritance : public Derived1, public Derived2 {
public:
    int derivedData;

    DiamondInheritance(int baseValue, int derived1Value, int derived2Value, int derivedValue)
        : VirtualBase(baseValue), Derived1(baseValue, derived1Value), Derived2(baseValue, derived2Value), derivedData(derivedValue) {}
};

int main() {
    NormalClass normalObj(42);
    std::cout << "Size of NormalClass object: " << sizeof(normalObj) << " bytes" << std::endl;

    Derived derivedObj(42, 99);
    std::cout << "Size of Derived object: " << sizeof(derivedObj) << " bytes" << std::endl;

    VirtualClass virtualObj(42);
    std::cout << "Size of VirtualClass object: " << sizeof(virtualObj) << " bytes" << std::endl;

    DerivedWithVirtual derivedWithVirtualObj(42, 99);
    std::cout << "Size of DerivedWithVirtual object: " << sizeof(derivedWithVirtualObj) << " bytes" << std::endl;

    DerivedWithMoreVirtual derivedWithMoreVirtualObj(42, 99);
    std::cout << "Size of DerivedWithMoreVirtual object: " << sizeof(derivedWithMoreVirtualObj) << " bytes" << std::endl;

    MultipleInheritance multipleInheritanceObj(42, 99, 123);
    std::cout << "Size of MultipleInheritance object: " << sizeof(multipleInheritanceObj) << " bytes" << std::endl;

    DiamondInheritance diamondInheritanceObj(42, 99, 88, 123);
    std::cout << "Size of DiamondInheritance object: " << sizeof(diamondInheritanceObj) << " bytes" << std::endl;

    return 0;
}