#include <iostream>
using namespace std;

class base {
 public:
  virtual void func1() { cout << "print base."; };
  void(*fp) = nullptr;
};

class son1 : public virtual base {
 public:
  virtual void func1() { cout << "print son."; };
};

int main() {
  base obj1;
  son1 obj2;

  base *p;
  p = &obj2;

  void (base::*tmp1)() = &base::func1;
  void (son1::*tmp2)() = &son1::func1;

  cout << (int *)(&obj1) << endl;  // 虚函数表地址
  cout << (int *)(&obj2) << endl;

  p->func1();
  // 当我们通过p->func1()调用虚函数时，虚函数表会根据对象的实际类型动态绑定函数调用。
  // 由于 p 指向一个派生类对象，所以会调用派生类中重写的func1()函数
  // 这说明了派生类与基类共享虚函数表，但是指针不同
}