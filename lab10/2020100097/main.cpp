#include <iostream>  
#include <vector>  
#include <cassert>  
using namespace std;  
  
// 基类  
class Base {  
public:  
    int a;  
    virtual void f() {}  
};  
  
// 继承类  
class Derived : public Base {  
public:  
    int b;  
    void f() override {}  
};  
  
// 带虚函数的类  
class VirtualBase {  
public:  
    virtual void f() {}  
};  
  
// 基类有虚函数的子类  
class VirtualDerived : public VirtualBase {  
public:  
    void f() override {}  
    void g() {} 
};  
  
// 多继承的类对象  
class MultiBase1 { };  
class MultiBase2 { };  
class MultiDerived : public MultiBase1, public MultiBase2 { }; 
  
// 虚基类的类对象  
class VirtualGrand : virtual public Base { }; 
class VirtualDerived2 : public Base, public VirtualGrand { };
  
int main() {  
    // 一般类
    Base base;  
    base.a = 10;   
    cout << "Base object: a = " << base.a << endl; 
    cout << "sizeof(Base) = " << sizeof(base) << endl; 
    cout << endl;  
    
    // 继承类  
    Derived derived;  
    derived.a = 20;   
    derived.b = 30;   
    cout << "Derived object: a = " << derived.a << ", b = " << derived.b << endl;
    cout << "sizeof(Derived) = " << sizeof(derived) << endl;
    cout << endl;  
    
    // 带虚函数的类
    VirtualBase virtualBase;   
    virtualBase.f();   
    cout << "VirtualBase object: called f()" << endl; 
    cout << "sizeof(VirtualBase) = " << sizeof(virtualBase) << endl; 
    cout << endl;  
    
    // 基类有虚函数的子类 
    VirtualDerived virtualDerived; 
    virtualDerived.f(); 
    virtualDerived.g(); 
    cout << "VirtualDerived object: called f()" << endl; 
    cout << "sizeof(VirtualDerived) = " << sizeof(virtualDerived) << endl; 
    
    return 0;
    }