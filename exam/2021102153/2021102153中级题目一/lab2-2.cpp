#include<iostream>
using namespace std;
class Object
{
public:
    void a1(){};//普通成员函数
    virtual void b1(){};//虚成员函数
    static void c1(){};//静态成员函数
    int d1;//普通成员属性
    double d2;
    int d3;
    void(*fp)=nullptr;
};
class Object2:public Object
{
    public:
virtual void b1(){cout <<"a";};
};

class Object3:public Object
{
    public:
virtual void b1(){cout <<"c";};
virtual void b2(){};
};
class Object5 : public Object2,public Object3//多继承的类对象(菱形继承)
{
int b;
};
class Object9
{
public:
	    void a1(){};//普通成员函数
    virtual void b1(){};//虚成员函数
    static void c1(){};//静态成员函数
    int d1;//普通成员属性
    double d2;
    int d3;
    void(*fp)=nullptr;
};

class Object6 : virtual public Object9
{
public:
virtual void b1(){cout <<"c";};
};

class Object7 : virtual public Object9
{
public:
virtual void b1(){cout <<"c";};
virtual void b2(){};
};

class Object8 : public Object6, public Object7//虚基类的类对象
{
public:
virtual void b1(){cout <<"c";};
};
int main()
{
    Object5 t4;
    Object8 t5;
    cout << sizeof(t4)<<endl << sizeof(t5);
}