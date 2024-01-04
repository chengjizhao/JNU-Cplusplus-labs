#include <iostream>  
  
class Base 
{  
    public:  
    virtual void foo() {}  
};  
  
class Derived : public Base {};  
  
int main() 
{  
    Derived d1, d2;  
    Base* ptr1 = &d1;  
    Base* ptr2 = &d2;  
  
    // 获取虚函数表指针  
    void** vtable1 = &reinterpret_cast<Base*>(ptr1)->foo;  
    void** vtable2 = &reinterpret_cast<Base*>(ptr2)->foo;  
  
    // 检查两个对象的虚函数表是否相同  
    std::cout << "vtable1: " << vtable1 << "\n";  
    std::cout << "vtable2: " << vtable2 << "\n";  
    if (vtable1 == vtable2) 
    {  
        std::cout << "The vtables are the same\n";  
    } 
    else 
    {  
        std::cout << "The vtables are different\n";  
    }  
  
    return 0;  
}