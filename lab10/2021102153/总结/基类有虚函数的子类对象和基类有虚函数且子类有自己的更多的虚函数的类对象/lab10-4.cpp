#include<iostream>
using namespace std;
class Object//带虚函数的类对象，一般类对象
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

class Object1:public Object//基类有虚函数的子类对象
{
double l;
};

class Object2:public Object//继承类对象（重写虚函数）
{
    public:
virtual void b1(){cout <<"a";};
};

class Object3:public Object//基类有虚函数且子类有自己的更多的虚函数的类对象
{
    public:
virtual void b1(){cout <<"c";};
virtual void b2(){};
};
int main()
{
    Object a;
    Object1 t;
    Object2 t1;
    Object3 t2;
    void(Object::*fp1)()=&Object::b1;
    void(Object1::*fp2)()=&Object1::b1;
    void(Object2::*fp3)()=&Object2::b1;
    void(Object3::*fp4)()=&Object3::b1;
    void(Object3::*fp5)()=&Object3::b2;
    cout << "a中虚函数表地址为"  << (int *)(&a) << endl;
    cout << "t中虚函数表地址为"  << (int *)(&t) << endl;
    cout << "t1中虚函数表地址为"  << (int *)(&t1) << endl;
    cout << "t2中虚函数表地址为"  << (int *)(&t2) << endl;
    cout << "a中第一个虚函数指针地址为"  << reinterpret_cast<void*>(a.*fp1) << endl;
    cout << "t中第一个虚函数指针地址为"  << reinterpret_cast<void*>(t.*fp2) << endl;
    cout << "t1中第一个虚函数指针地址为"  << reinterpret_cast<void*>(t1.*fp3) << endl;
    cout << "t2中第一个虚函数指针地址为"  << reinterpret_cast<void*>(t2.*fp4) << endl;
    cout << "t2中第二个虚函数指针地址为"  << reinterpret_cast<void*>(t2.*fp5) << endl;
    //所有成员函数都存放在代码区，其中除了虚函数，其它所有成员函数地址通过编译器获取；
//虚函数存放在代码区，与其它成员函数不同的是，虚函数地址存放在与该对象关联的虚表中；
//普通成员变量存放在对象内，遵循字节对齐原则存放。
//结果为a中虚函数表地址为0x61fdf0
/*t中虚函数表地址为0x61fdc0
t1中虚函数表地址为0x61fd90
t2中虚函数表地址为0x61fd60
a中第一个虚函数指针地址为0x402fe0
t中第一个虚函数指针地址为0x402fe0
t1中第一个虚函数指针地址为0x403080
t2中第一个虚函数指针地址为0x4030e0
t2中第二个虚函数指针地址为0x403110*/
//由虚函数表可知，每个类对象都有自己的虚函数表,若子类没有覆盖父类的虚函数，则子类和父类的虚函数共用同一个虚函数地址。
//若子类覆盖了任意一个父类的虚函数，或者子类定义了新的虚函数，那么子类的虚函数表其中对应的函数指针被覆盖。其它成员和普通的类对象及其子类对象一致。
//排序为先父类后子类
}