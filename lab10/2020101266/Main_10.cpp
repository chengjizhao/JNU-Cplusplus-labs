#include <iostream>  
#include <memory>  

// 基类A  
class A {
public:
    int a;
    virtual void f() { std::cout << "A::f()" << std::endl; }
};

// 基类B  
class B {
public:
    int b;
    virtual void g() { std::cout << "B::g()" << std::endl; }
};

// 派生类C同时继承自A和B  
class C : public A, public B {
public:
    int c;
    void f() override { std::cout << "C::f()" << std::endl; } // 重写A的f()  
    void g() override { std::cout << "C::g()" << std::endl; } // 重写B的g()  
};

int main() {
    std::cout << "sizeof(A) = " << sizeof(A) << std::endl; // 输出A的大小，假设为X1字节  
    std::cout << "sizeof(B) = " << sizeof(B) << std::endl; // 输出B的大小，假设为X2字节  
    std::cout << "sizeof(C) = " << sizeof(C) << std::endl; // 输出C的大小，假设为X3字节  
    return 0;
}

/*一般类对象：
内存布局：对象的成员变量按照声明的顺序存储在一块连续的内存区域中。
继承类对象：

内存布局：子类对象首先包含父类对象的所有成员变量，然后是子类自己的成员变量。如果父类也有虚函数表（vtable），则子类对象还会包含一个指向父类vtable的指针。
带虚函数的类对象：

内存布局：除了成员变量外，对象还有一个指向虚函数表的指针（vptr）。虚函数表包含了类的所有虚函数的地址。
基类有虚函数的子类对象：

内存布局：子类对象首先包含基类的所有成员变量（包括从其他继承的基类），然后是子类自己的成员变量。基类的vtable会被添加到子类对象的开始位置，然后是子类的vptr。
基类有虚函数且子类有自己的更多的虚函数的类对象：

内存布局：在这种情况下，子类的vtable会包含基类的虚函数以及子类自己的虚函数。子类的vptr将指向这个合并的vtable。
多继承的类对象：

内存布局：更复杂，取决于继承的顺序和方式。可能会有多个vptr和多个vtable（一个对应每个基类）。也可能有菱形继承问题，此时需要虚继承来解决。
虚基类的类对象：

内存布局：使用虚继承可以确保共享的基类只被存储一次，但具体的布局取决于编译器和继承的方式。通常，会有一个指向共享基类的指针和一个指向该基类的vtable的指针。*/