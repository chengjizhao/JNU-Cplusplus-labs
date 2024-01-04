/*虚析构函数是指基类的析构函数被声明为虚函数，这样当用基类指针删除派生类对象时，可以自动调用派生类的析构函数，避免内存泄漏或其他问题。虚析构函数是一种多态的体现，它可以根据指针所指向的对象的实际类型执行相应的析构函数。*/
#include <iostream>
using namespace std;

class Base //基类
{
public:
    Base() { cout << "Base constructor" << endl; }
    virtual ~Base() { cout << "Base destructor" << endl; } //虚析构函数
};

class Derived : public Base //派生类
{
public:
    Derived() { cout << "Derived constructor" << endl; }
    ~Derived() { cout << "Derived destructor" << endl; }
};

int main()
{
    Base *p = new Derived(); //基类指针指向派生类对象
    delete p; //释放指针
    return 0;
}
/*输出结果说明，delete p; 语句引发了派生类和基类的析构函数都被调用，这样就保证了派生类对象被正确地释放。如果基类的析构函数不是虚函数，那么只会调用基类的析构函数，导致派生类对象的部分资源没有被回收，造成内存泄漏或其他错误。*/