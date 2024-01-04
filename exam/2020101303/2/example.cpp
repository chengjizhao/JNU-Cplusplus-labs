#include <iostream>
using namespace std;

class Base 
{
    public:
       virtual void vBase() {cout << "Virtual Base !" << endl;}
       virtual void Public() {cout << "Public: Base" << endl;}
       void (*fptr)() = nullptr;
};

class Derived : public Base
{
    public:
       virtual void vDerived() {cout << "Virtual Derived !" << endl;}
       void Public() override {cout << "Public: Derived" << endl;}
};

int main() 
{
    Base base_obj;
    Derived derived_obj;

    //地址及调用
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
