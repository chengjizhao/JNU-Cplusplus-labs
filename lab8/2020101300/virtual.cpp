/*在C++中，虚函数(virtual function)是一种在基类中声明的函数，它可以在派生类中被重写。虚函数的主要目的是实现动态多态性，即在运行时根据对象的实际类型来决定调用哪个函数。
为了实现虚函数调用，C++使用了一种叫做虚函数表（vtable）的数据结构。每个有虚函数的类（也就是从含有虚函数的类派生出来的类）都有一个虚函数表。这个表是一个函数指针数组，数组中的每个元素都是指向类中的虚函数的指针。
每个派生类对象中都包含一个指向其虚函数表的指针，这个指针称为虚函数指针（vptr）。当一个对象被创建时，它的虚函数指针就会被初始化为指向其所属类的虚函数表的指针。
在运行时，当调用一个对象的虚函数时，程序首先会通过这个对象的虚函数指针找到它的虚函数表，然后在表中查找对应的函数指针，然后通过这个指针来调用对应的函数。
对于多个不同对象是否指向同一个虚函数表的问题，答案是它们指向的是同一个虚函数表。因为每个类都有自己的虚函数表，所以每个类的对象都会有一个指向自己类的虚函数表的指针。即使两个对象属于不同的类，它们的虚函数表也是不同的。
下面是一个简单的程序来证明这个结论：*/

#include <iostream>  
  
class Base {  
public:  
    virtual void func() { std::cout << "Base func\n"; }  
};  

class Derived : public Base {  
public:  
    void func() override { std::cout << "Derived func\n"; }  
};  
  
int main() {  
    Base* base1 = new Derived();  
    Base* base2 = new Derived();  
      
    if (base1->vptr == base2->vptr) {  
        std::cout << "The vptrs are the same\n";  
    } else {  
        std::cout << "The vptrs are different\n";  
    }  
      
    delete base1;  
    delete base2;  
      
    return 0;  
}

/*在这个程序中，我们创建了两个派生自Base的类的对象，然后比较了它们的虚函数指针（vptr）。如果它们指向同一个虚函数表，那么这两个指针就会相等；否则，它们就会不相等。这个程序的输出应该是"The vptrs are different"，因为每个对象都有自己的虚函数表。*/