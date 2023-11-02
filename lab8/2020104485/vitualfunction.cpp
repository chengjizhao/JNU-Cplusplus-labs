#include <iostream>

class Base {
public:
 virtual void foo() {
 std::cout << "Base::foo()" << std::endl;
 }
};

class Derived : public Base {
public:
 void foo() override {
 std::cout << "Derived::foo()" << std::endl;
 }
};

int main() {
 Base* basePtr1 = new Base();
 Base* basePtr2 = new Derived();

 // 获取虚函数表指针 
uintptr_t* vptr1 = reinterpret_cast<uintptr_t*>(basePtr1);
uintptr_t* vptr2 = reinterpret_cast<uintptr_t*>(basePtr2);

 // 输出虚函数表地址 
 std::cout << "vptr1: " << vptr1 << std::endl;
  std::cout << "vptr2: " << vptr2 << std::endl;

 delete basePtr1;
 delete basePtr2;

 return 0;
}
