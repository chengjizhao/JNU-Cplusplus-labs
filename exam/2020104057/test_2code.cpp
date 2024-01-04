#include <iostream>

using namespace std;

// 委托类
class Subject {
public:
  virtual void doSomething() = 0;
};

// 代理类
class Proxy : public Subject {
private:
  Subject* subject;

public:
  Proxy(Subject* subject) {
    this->subject = subject;
  }

  virtual void doSomething() {
    subject->doSomething();
  }
};


int main() 
{
  Subject* subject = new Subject();
  Proxy* proxy = new Proxy(subject);

  proxy->doSomething();

  return 0;
}

/*说明虚指针是如何被使用的:
在上面的代码实例中，Subject 类是委托类，Proxy 类是代理类。Proxy 类通过继承 Subject 类，实现了 doSomething() 虚函数。

在 main() 函数中，创建了一个 Subject 对象和一个 Proxy 对象。然后，通过 Proxy 对象调用 doSomething() 虚函数。由于 Proxy 类实现了 doSomething() 虚函数，所以这个调用会被转发到 Subject 对象的 doSomething() 函数。*/
