//基类指针可以指向派生类的对象，如果删除指针；就会调用该指针指向的派生类析构函数，而派生类的析构函数又自动调用基类的析构函数，这样整个派生类的对象完全被释放。如果析构函数不被声明成虚函数，则编译器实施静态绑定，在删除基类指针时，只会调用基类的析构函数而不调用派生类析构函数，这样就会造成派生类对象析构不完全。所以，将析构函数声明为虚函数是十分必要的。

#include <iostream>  
#include <string>  
  
class Base {  
public:  
    virtual ~Base() {  
        std::cout << "Base::~Base()" << std::endl;  
    }  
};  
  
class Derived : public Base {  
public:  
    ~Derived() {  
        std::cout << "Derived::~Derived()" << std::endl;  
    }  
};  
  
int main() {  
    Base* ptr = new Derived();  
    delete ptr; // 如果没有将Base的析构函数声明为虚函数，这里只会调用Base::~Base()，而不会调用Derived::~Derived()
    return 0;  
}
