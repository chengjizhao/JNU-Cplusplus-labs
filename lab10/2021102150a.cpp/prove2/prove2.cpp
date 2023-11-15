#include <iostream>
using namespace std;

class base {
 public:
  int a;
  virtual void func1() { cout << "base::func1" << endl; };
  virtual void func2() { cout << "base::func2" << endl; };
};

class son : public base {
 public:
  virtual void func1() { cout << "son::func1" << endl; }
};

int main() {
  typedef void (base::*P)();
  typedef void (son::*p)();

  base obj1;
  son obj2;

  long* vp = reinterpret_cast<long*>(&obj1);
  P pFunc1 = &base::func1;
  P pFunc2 = &base::func2;
  unsigned int* tmp1 = (unsigned*)&pFunc1;
  unsigned int* tmp2 = (unsigned*)&pFunc2;
  cout << "基类的内存地址为：" << endl;
  cout << vp << " " << sizeof(vp) << endl;
  cout << &(obj1.a) << " " << sizeof(obj1.a) << endl;
  cout << hex << tmp1 << " " << sizeof(tmp1) << endl;
  cout << hex << tmp2 << " " << sizeof(tmp2) << endl;
  /*++++++++++++++++++++++++++++++++++++++++++++++*/
  cout << endl << "子类的内存结构为：" << endl;
  long* vps = reinterpret_cast<long*>(&obj2);
  p pFunc1s = &son::func1;
  p pFunc2s = &son::func2;
  unsigned int* tmp1s = (unsigned*)&pFunc1s;
  unsigned int* tmp2s = (unsigned*)&pFunc2s;
  cout << vps << endl;
  cout << &(obj2.a) << endl;
  cout << hex << tmp1s << endl;
  cout << hex << tmp2s << endl;
  return 0;
}