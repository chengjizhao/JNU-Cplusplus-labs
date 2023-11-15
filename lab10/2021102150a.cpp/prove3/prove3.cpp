#include <iostream>
using namespace std;

class base {
 public:
  virtual void func1(){};
  void(*fp) = nullptr;
};

class son1 : public virtual base {
 public:
  virtual void func2(){};
};

class son2 : public virtual base {
 public:
  virtual void func3(){};
};

class grend : public virtual son1, public virtual son2 {
 public:
  virtual void func4(){};
};

int main() {
  grend obj1;
  son1 obj2;
  son2 obj3;
  grend obj4;

  void (base::*tmp1)() = &base::func1;
  void (son1::*tmp2)() = &son1::func2;
  void (son2::*tmp3)() = &son2::func3;
  void (grend::*tmp4)() = &grend::func4;

  cout << (int *)(&obj1) << endl;  // 虚函数表地址
  cout << (int *)(&obj2) << endl;
  cout << (int *)(&obj3) << endl;
  cout << (int *)(&obj4) << endl;
  cout << reinterpret_cast<void *>(obj1.*tmp1) << endl;  // 成员函数地址
  cout << reinterpret_cast<void *>(obj2.*tmp2) << endl;
  cout << reinterpret_cast<void *>(obj3.*tmp3) << endl;
  cout << reinterpret_cast<void *>(obj4.*tmp4) << endl;
}