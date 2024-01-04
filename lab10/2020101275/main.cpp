#include <iostream>
using namespace std;

// 一般类对象
class GeneralClass {
public:
    int generalVar;
};

// 继承类对象
class DerivedClass : public GeneralClass {
public:
    int derivedVar;
};

// 带虚函数的类对象
class VirtualClass {
public:
    virtual void virtualFunc1() {}
    virtual void virtualFunc2() {}
};

// 基类有虚函数的子类对象
class SubClass : public VirtualClass {
public:
    int subVar;
};

// 基类有虚函数且子类有自己的更多的虚函数的类对象
class MoreVirtualClass : public VirtualClass {
public:
    virtual void moreVirtualFunc1() {}
    virtual void moreVirtualFunc2() {}
};

// 多继承的类对象
class MultipleInherit : public GeneralClass, public VirtualClass {
public:
    int multipleVar;
};

// 虚基类的类对象
class VirtualBase {
public:
    int virtualBaseVar;
};
class DerivedFromVirtualBase : virtual public VirtualBase {
public:
    int derivedFromVirtualBaseVar;
};

int main() { 

    // 一般类对象
    GeneralClass generalObj;
    cout << "sizeof(GeneralClass): " << sizeof(generalObj) << endl;

    // 继承类对象
    DerivedClass derivedObj;
    cout << "sizeof(DerivedClass): " << sizeof(derivedObj) << endl;

    // 带虚函数的类对象
    VirtualClass virtualObj;
    cout << "sizeof(VirtualClass): " << sizeof(virtualObj) << endl;

    // 基类有虚函数的子类对象
    SubClass subObj;
    cout << "sizeof(SubClass): " << sizeof(subObj) << endl;

    // 基类有虚函数且子类有自己的更多的虚函数的类对象
    MoreVirtualClass moreVirtualObj;
    cout << "sizeof(MoreVirtualClass): " << sizeof(moreVirtualObj) << endl;

    // 多继承的类对象
    MultipleInherit multipleObj;
    cout << "sizeof(MultipleInherit): " << sizeof(multipleObj) << endl;

    // 虚基类的类对象
    DerivedFromVirtualBase derivedVirtualBaseObj;
    cout << "sizeof(DerivedFromVirtualBase): " << sizeof(derivedVirtualBaseObj) << endl;

    // 输出虚函数表的地址
    cout << "Virtual function table addresses:" << endl;
    cout << "VirtualClass: " << reinterpret_cast<void**>(&virtualObj) << endl;
    cout << "SubClass: " << reinterpret_cast<void**>(&subObj) << endl;
    cout << "MoreVirtualClass: " << reinterpret_cast<void**>(&moreVirtualObj) << endl;

    return 0;
    
}