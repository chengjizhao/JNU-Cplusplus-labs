#include <iostream>
using namespace std;

//继承类对象，基类有虚函数的子类对象，基类有虚函数且子类有自己的更多的虚函数的类对象

class Base 
{
    public:
       int a;
       virtual void vBase() {cout << "Virtual Base !" << endl;}
       virtual void Public() {cout << "Public: Base" << endl;}
       void (*fptr)() = nullptr;
};

class Derived : public Base
{
    public:
       int b;
       virtual void vDerived() {cout << "Virtual Derived !" << endl;}
       void Public() override {cout << "Public: Derived" << endl;}
};

int main() 
{
    Base base_obj;
    Derived derived_obj;

    //所占内存大小
    cout << "Size of Base: " << sizeof(base_obj) << " bytes" << endl;
    cout << "Size of Derived: " << sizeof(derived_obj) << " bytes" << endl;

    //地址及调用
    int *a_ptr = &derived_obj.a;
    int *b_ptr = &derived_obj.b;
    void *f = &derived_obj.fptr;
    cout << "Address of a: " << reinterpret_cast<void*>(a_ptr) << endl;
    cout << "Address of *fptr: " << reinterpret_cast<void*>(f) << endl;
    cout << "Address of b: " << reinterpret_cast<void*>(b_ptr) << endl;

    void (Base::*fptr_1)() = &Base::vBase;
    cout << "Address of Base::vBase: " << reinterpret_cast<void*>(base_obj.*fptr_1) << endl;
    (base_obj.*fptr_1)();
    void (Base::*fptr_2)() = &Base::Public;
    cout << "Address of Base::Public: " << reinterpret_cast<void*>(base_obj.*fptr_2) << endl;
    (base_obj.*fptr_2)();

    void (Derived::*fptr1)() = &Derived::vBase;
    cout << "Address of Derived::vBase: " << reinterpret_cast<void*>(derived_obj.*fptr1) << endl;
    (derived_obj.*fptr1)();
    void (Derived::*fptr2)() = &Derived::Public;
    cout << "Address of Derived::Public: " << reinterpret_cast<void*>(derived_obj.*fptr2) << endl;
    (derived_obj.*fptr2)();
    void (Derived::*fptr3)() = &Derived::vDerived;
    cout << "Address of Derived::vDerived: " << reinterpret_cast<void*>(derived_obj.*fptr3) << endl;
    (derived_obj.*fptr3)();
    
    return 0;
}
