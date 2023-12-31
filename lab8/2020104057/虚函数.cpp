#include <iostream>


class Derived : public Base
{
  public:
    void print() override 
    {
      std::cout << "Derived class" << std::endl;
    }
};

class Base 
{
  public:
    virtual void print() 
    {
      std::cout << "Base class" << std::endl;
    }
};


int main() 
{
  Base obj1;
  Derived obj2;
  Base* ptr1 = &obj1;
  Base* ptr2 = &obj2;

// 打印虚函数表地址
  std::cout << "Object 1 vtable address: " << *((void**)(&obj1)) << std::endl;
  std::cout << "Object 2 vtable address: " << *((void**)(&obj2)) << std::endl;

// 调用虚函数
  ptr1->print();
  ptr2->print();
  system("pause");
  return 0;
}