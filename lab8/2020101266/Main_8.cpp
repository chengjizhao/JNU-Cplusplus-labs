#include <iostream>  
#include <vector>  

//虚函数是C++中实现多态的一种机制，其实现依赖于虚函数表（vtable）。每个包含虚函数的类都会有一个虚函数表，该表包含了类中所有虚函数的地址。每个对象的虚函数表指针（vptr）都会指向其所属类的虚函数表。
//当一个类继承自另一个包含虚函数的类时，子类的构造函数会负责初始化其vptr，使其指向自己的虚函数表。

class Base {
public:
    virtual void func() { std::cout << "Base::func()" << std::endl; }
};

class Derived : public Base {
public:
    void func() override { std::cout << "Derived::func()" << std::endl; }
};

int main() {
    std::vector<Base*> objects;
    for (int i = 0; i < 10; ++i) {
        objects.push_back(new Derived());
    }

    for (auto obj : objects) {
        obj->func(); // 输出 "Derived::func()" 10次  
    }

    for (auto obj : objects) {
        std::cout << "vptr address: " << &obj->vptr() << std::endl; // 输出每个对象的vptr地址  
    }

    for (auto obj : objects) {
        delete obj; // 释放内存  
    }
    objects.clear();

    return 0;
}