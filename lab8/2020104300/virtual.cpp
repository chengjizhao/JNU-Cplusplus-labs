//在C++中，虚函数是一种动态绑定机制，它允许在运行时根据对象的实际类型确定要调用的函数。实现虚函数的关键是虚函数表（vtable），这是一个在每个有虚函数的类中都存在的成员。

//虚函数表存储在类的首部：在内存中，虚函数表存储在类的首部，紧挨着类中的数据成员。虚函数表是一个函数指针数组，数组中每个元素都是一个指向虚函数的指针。
//不同对象不共用同一虚函数表：每个类都自己的虚函数表，不同对象的类实例并不共享同一个虚函数表。

#include <iostream>  
  
class Base {  
public:  
    virtual void foo() {}  
};  
  
class Derived : public Base {};  
  
int main() {  
    Derived d1, d2;  
    Base* ptr1 = &d1;  
    Base* ptr2 = &d2;  
  
    // 获取虚函数表指针  
    void** vtable1 = &reinterpret_cast<Base*>(ptr1)->foo;  
    void** vtable2 = &reinterpret_cast<Base*>(ptr2)->foo;  
  
    // 检查两个对象的虚函数表是否相同  
    std::cout << "vtable1: " << vtable1 << "\n";  
    std::cout << "vtable2: " << vtable2 << "\n";  
    if (vtable1 == vtable2) {  
        std::cout << "The vtables are the same\n";  
    } else {  
        std::cout << "The vtables are different\n";  
    }  
  
    return 0;  
}
//这个程序应该输出"The vtables are different"，因为尽管d1和d2都是Derived类的实例，但它们的虚函数表应该是不同的。这就证明了每个对象都有自己的虚函数表。
