//调研如下：
//虚函数和动态绑定是一种强大的面向对象编程特性。它们的实现是基于一种称为"虚函数表"（或vtable）的机制。
//每个有虚函数的类都会有一个虚函数表，这是一个包含指向类中虚函数的指针数组。
//1.每个类的虚函数表都存储在静态内存中，具体位置通常在编译时决定。
//每个虚函数表包含一个指向虚函数的指针数组。如果一个类有n个虚函数，那么虚函数表就有n个元素。
//2.对于同一个类的所有对象，它们都会指向同一个虚函数表。这就是实现多态的基础，
//即不论创建多少个对象，只要它们是同一个类的实例，那么它们都会共享相同的虚函数表。
//验证调研：创建了两个 Derived 类的对象，并将它们的地址赋值给了 Base 类型的指针 base1 和 base2。
//然后使用 memcmp 函数比较这两个指针的值。如果它们相等，那么说明两个不同的对象实例指向了同一个虚函数表，即验证了调研结果。
#include <iostream>  
#include <string.h>  
  
class Base {  
public:  
    virtual void foo() { std::cout << "Base::foo\n"; }  
};  
  
class Derived : public Base {  
public:  
    void foo() override { std::cout << "Derived::foo\n"; }  
};  
  
int main() {  
    Base* base1 = new Derived();  
    Base* base2 = new Derived();  
      
    // 打印base1和base2的内存地址，观察它们是否相同  
    std::cout << "base1 address: " << base1 << "\n";  
    std::cout << "base2 address: " << base2 << "\n";  
    std::cout << "Are base1 and base2 pointing to the same memory location? ";  
    if (memcmp(base1, base2, sizeof(Base*)) == 0) {  
        std::cout << "Yes\n";  
    } else {  
        std::cout << "No\n";  
    }  
      
    delete base1;  
    delete base2;  
      
    return 0;  
}