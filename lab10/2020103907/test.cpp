#include <iostream>
using namespace std;
// 一般类对象
class Base {
public:
    int basedata;
};

// 继承类对象
class Derived : public Base {
public:
    int deriveddata;
};

// 带虚函数的类对象
class Base1 {
public:
    int basedata1;
    virtual void virtualFunction1() {}
};

// 基类有虚函数的子类对象
class Derived1 : public Base1{
public:
    int deriveddata1;
    void virtualFunction1() override {}
};

// 基类有虚函数且子类有自己的更多的虚函数的类对象
class Derived2 : public Base1 {
public:
    int deriveddata2;
    virtual void virtualFunctionDerived1() {}
    virtual void virtualFunctionDerived2() {}
};

//多继承的类对象
class Base2 {
public:
    int basedata2;
    virtual void virtualFunction2() {}
};

class Derived3 : public Base1, public Base2 {
public:
    int deriveddata3;
    void virtualFunctionDerived2() {}
};

//虚基类的类对象
class VirtualBase {
public:
    int virtualdata;
    virtual void virtualFunction3() {}
};

class DerivedVB1 : virtual public VirtualBase {
public:
    int derivedVB1;
    void derivedVBFunction1() {}
};

class DerivedVB2 : virtual public VirtualBase {
public:
    int derivedVB2;
    void derivedVBFunction2() {}
};

class FinalDerived : public DerivedVB1, public DerivedVB2 {
public:
    int finalDerivedVB;
    void finalDerivedVBFunction() {}
};

int main() {
// 一般类对象
    Base baseObj;
    cout << "Size of Base: " << sizeof(Base) << " bytes\n";
    cout << "Adress of Base: " << reinterpret_cast<void**>(&baseObj)  << endl;
    
// 继承类对象
    Derived derivedObj;
    cout << "Size of Derived: " << sizeof(Derived) << " bytes\n";
    cout << "Adress of Derived: " << reinterpret_cast<void**>(&derivedObj)  << endl;

// 带虚函数的类对象
    Base1 baseObj1;
    cout << "Size of Base1: " << sizeof(Base1) << " bytes\n";
    cout << "Adress of Base1: " << reinterpret_cast<void**>(&baseObj1)  << endl;

// 基类有虚函数的子类对象
    Derived1 derivedObj1;
    cout << "Size of Derived1: " << sizeof(Derived1) << " bytes\n";
    cout << "Adress of Derived1: " << reinterpret_cast<void**>(&derivedObj1)  << endl;
    
// 基类有虚函数且子类有自己的更多的虚函数的类对象
    Derived2 derivedObj2;
    cout << "Size of Derived2: " << sizeof(Derived2) << " bytes\n";
    cout << "Adress of Derived2: " << reinterpret_cast<void**>(&derivedObj2)  << endl;
    
//多继承的类对象
    Derived3 derivedObj3;
    cout << "Size of Derived3: " << sizeof(Derived3) << " bytes\n";
    cout << "Adress of Derived3: " << reinterpret_cast<void**>(&derivedObj3)  << endl;

//虚基类的类对象
    FinalDerived finalDerivedObj;
    cout << "Size of FinalDerived: " << sizeof(FinalDerived) << " bytes\n";
    cout << "Adress of FinalDerived: " << reinterpret_cast<void**>(&finalDerivedObj)  << endl;

    return 0;
}
