#include <iostream>
using std::cout,std::endl;using FUNC = void(*)();
//1一般类对象
class General
{
public:	
    int a;		
	int test2()  {return a ;}
};
//2继承类对象——基类general子类son
class Son : public General
{
public:
    int b;
};
//3带虚函数的类对象
class Base
{
public:
    int c;
    virtual void print()
    {
        cout << "使用地址调用虚函数：有虚函数的类对象&基类有虚函数" << endl;
    }
};
//4基类有虚函数的子类对象
class Dve : public Base
{
public:
};
//5基类有虚函数且子类有自己的更多的虚函数的类对象
class Diver : public Base
{
public:
    virtual void print()
    {
        cout << "子类虚函数对基类的重写" << endl;
    }
    virtual void otherprint()
    {
        cout << "子类虚函数比基类多的一个" << endl;
    }
};
//6多继承的类对象
class Base1
{
public:
    int f1;
    void print()
    {
        cout << "多继承1" << endl;
    }
};
class Base2
{
public:
    int f2;
    void print()
    {
        cout << "多继承2" << endl;
    }
};
class Driver : public Base1, public Base2{
    public:
    int many;
};
//7虚基类的类对象
class B
{
public:
    int ib;
    virtual void print(){
        cout << "基类1" << endl;
    }
};

class B1 : virtual public B
{
public:
    int ib1;
    virtual void print(){
        cout << "子类1" << endl;
    }
    virtual void addprint(){
        cout << "子类2" << endl;
    }
};