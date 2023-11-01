#include <iostream>

using namespace std;

class Base 
{
public:
	virtual void a() { cout << "a()" << endl; }
	virtual void b() { cout << "b()" << endl; }
  void(*fp)=nullptr;
};
class Devired :public Base
{
public:
  
  virtual void b() { cout << "Derive::b()" << endl;//覆写虚函数
  }
};
class Devired2 : public Base
{

};
int main() 
{
	
 //同一类不同对象指向同一个虚表
 
  Base x1;
  Base x2;
  void(Base::*fp1)()=&Base::a;
  void(Base::*fp2)()=&Base::b;
  
  //没有覆盖函数的子类的虚函数地址
  Devired s1;
  void(Devired::*fp3)()=&Devired::a;
  //覆盖了第二个函数的子类的虚函数地址
  void(Devired::*fp4)()=&Devired::b;
  cout << "x1虚函数表地址：" << (void*)(&x1) << endl;//基类对象1虚函数表地址
  cout << "x2虚函数表地址：" << (void*)(&x2) << endl;//基类对象1虚函数表地址
  cout << "x1虚函数表第一个虚函数指针地址：" <<reinterpret_cast<void*>(x1.*fp1) << endl;
  cout << "x2虚函数表第二个虚函数指针地址：" <<reinterpret_cast<void*>(x1.*fp2) << endl;
  cout << "x1虚函数表第一个虚函数指针地址：" <<reinterpret_cast<void*>(x2.*fp1) << endl;
  cout << "x2虚函数表第二个虚函数指针地址：" <<reinterpret_cast<void*>(x2.*fp2) << endl;
  cout << "子类对象虚函数1地址" <<reinterpret_cast<void*>(s1.*fp3) << endl;
  cout << "子类对象虚函数2地址" <<reinterpret_cast<void*>(s1.*fp4) << endl;
	return 0;
}
/*每一个类都有一张虚函数表，存储中这个类所有虚函数的入口地址。同一个类的两个对象共享类的虚函数表。
当一个对象被创建时，它会在内存中分配一块空间用于存储对象数据和指向虚函数表的指针。这个指针始终指向该类的虚函数表，不会因为对象的不同而改变。
如果派生类重写了基类的虚函数，那么派生类会在其自己的虚函数表中存储重写后的函数地址。如果派生类没有重写基类的虚函数，那么它会继承基类的虚函数地址，并将其复制到自己的虚函数表中。
*/

