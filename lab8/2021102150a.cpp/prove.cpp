#include <iostream>
using namespace std;

class A {
 private:
  int date1, date2;

 public:
  virtual void vfunc1() { cout << "调用vfunc1" << endl; };
};

class B : public A {
 private:
  int date3;

 public:
  virtual void vfunc1() { cout << "调用B中的vfunc1" << endl; };
  void func1();
};

int main() {
  A obj;
  long *vp = reinterpret_cast<long *>(&obj);
  cout << vp << endl;  // 运行结果为0x61fe00，位于只读数据段

  A A_obj;
  B b_Obj;
  A *p1 = &A_obj;
  p1->vfunc1();
  cout << p1 << endl;
  A *p2 = &b_Obj;
  p2->vfunc1();
  cout
      << p2
      << endl;  // 运行结果显示，两次调用的虚函数地址并不相同，说明基类和继承类有各自独立的虚函数表
  return 0;
}