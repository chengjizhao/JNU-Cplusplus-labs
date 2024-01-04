#include <iostream>
using namespace std;

class Base
{
    public:
       virtual void vFunc1() {cout << "vFunc1" << endl;};
       virtual void vFunc2() {cout << "vFunc2" << endl;};
       void (*ptr) () = nullptr;
};

class Derived_1 : public Base
{
    public:
       void vFunc1() override {cout << "dvFunc1" << endl;};
};

class Derived_2 : public Base
{
};

int main()
{
    Base base_obj_1;
    Base base_obj_2;
    Derived_1 derived_1_obj;
    Derived_2 derived_2_obj;

    //同一类不同对象指向同一个虚表
    void** vtable1 = *(void***)(&base_obj_1);
    void** vtable2 = *(void***)(&base_obj_2);
    cout << "基类对象1的虚表地址: " << vtable1 << endl;
    cout << "基类对象2的虚表地址: " << vtable2 << endl;
    if (vtable1 == vtable2)
    {
        cout << "同一类不同对象指向同一个虚表" << endl << endl;
    }
    
    //如果派生类没有覆盖基类的虚函数，其虚函数地址和基类相同。
    void (Base::*ptr_base_vFunc1) () = &Base::vFunc1;
    void (Base::*ptr_base_vFunc2) () = &Base::vFunc2;
    cout << "基类虚函数地址: " << endl;
    cout << reinterpret_cast<void*>(base_obj_1.*ptr_base_vFunc1) << endl;
    cout << reinterpret_cast<void*>(base_obj_1.*ptr_base_vFunc2) << endl;

    void (Derived_1::*ptr_derived1_vFunc1) () = &Derived_1::vFunc1;
    void (Derived_1::*ptr_derived1_vFunc2) () = &Derived_1::vFunc2;
    cout << "派生类1虚函数地址: " << endl;
    cout << reinterpret_cast<void*>(derived_1_obj.*ptr_derived1_vFunc1) << endl;
    cout << reinterpret_cast<void*>(derived_1_obj.*ptr_derived1_vFunc2) << endl;
    
    void (Derived_2::*ptr_derived2_vFunc1) () = &Derived_2::vFunc1;
    void (Derived_2::*ptr_derived2_vFunc2) () = &Derived_2::vFunc2;
    cout << "派生类2虚函数地址: " << endl;
    cout << reinterpret_cast<void*>(derived_2_obj.*ptr_derived2_vFunc1) << endl;
    cout << reinterpret_cast<void*>(derived_2_obj.*ptr_derived2_vFunc2) << endl; 
    
    return 0;
}