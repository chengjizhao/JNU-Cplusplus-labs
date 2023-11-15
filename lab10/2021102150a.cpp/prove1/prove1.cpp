#include <iostream>
using namespace std;

class base {
 public:
  int a, b;
};

class son : public base {
 public:
  int c, d;
};

int main() {
  typedef void (base::*p)();

  base obj1;
  son obj2;
  cout << sizeof(obj1) << endl << sizeof(obj2) << endl;
  cout << &(obj1.a) << " " << &(obj1.b) << endl;
  cout << &(obj2.c) << " " << &(obj2.d)
       << endl;  // 运行结果说明成员变量是按声明顺序一次排列的
}