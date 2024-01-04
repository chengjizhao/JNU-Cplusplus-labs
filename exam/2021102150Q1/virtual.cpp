#include <iostream>
class IDelegate {
 public:
  IDelegate() {}
  ~IDelegate()  // 非虚析构函数
  {
    std::cout << "~IDelegate()!" << std::endl;
  }
};

class CStaticDelegate : public IDelegate {
 public:
  CStaticDelegate() {}
  ~CStaticDelegate() { std::cout << "~CStaticDelegate()!" << std::endl; }

 private:
  int m_Func;
};

class CMethodDelegate : public IDelegate {
 public:
  CMethodDelegate() {}
  ~CMethodDelegate() { std::cout << "~CMethodDelegate()!" << std::endl; }
};

int main() {
  IDelegate* demo1 = new CStaticDelegate();
  IDelegate* demo2 = new CMethodDelegate();
  delete demo1;
  delete demo2;
}
// output:~IDelegate()!
//        ~IDelegate()!
//  由运行结果可知，对象销毁时只调用了父类的析构函数。
//  如果这时子类的析构函数中有关于内存释放的操作，将会造成内存泄露。所以需要给父类的析构函数加上virtual,即虚析构函数。
