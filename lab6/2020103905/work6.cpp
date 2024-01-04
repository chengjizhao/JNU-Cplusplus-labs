#include <iostream>

class MyClass {
private:
  void privateFunction() {
    std::cout << "私有成员函数被调用" << std::endl;
  }

public:
  void callPrivateFunction() {
    privateFunction();
  }
};

int main() {
  MyClass obj;
  obj.callPrivateFunction(); // 通过公有成员函数间接调用私有成员函数
  return 0;
}
//定义了一个名为privateFunction的私有成员函数，并在公有区域中定义了一个名为callPrivateFunction的公有成员函数。
//callPrivateFunction函数可以直接调用私有成员函数`privateFunction`，从而实现了间接调用私有成员函数的目的。
