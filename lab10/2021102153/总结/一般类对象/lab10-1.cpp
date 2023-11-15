#include<iostream>
using namespace std;
class Object//带虚函数的类对象，一般类对象
{
public:
    void a1(){};//普通成员函数
    static void c1(){};//静态成员函数
    double d2;
    int d1;//普通成员属性
    int d3;
};
class Object1//带虚函数的类对象，一般类对象
{
public:
    void a1(){};//普通成员函数
    static void c1(){};//静态成员函数
    int d1;//普通成员属性
    double d2;
    int d3;
};
int main()
{
    Object a;
    Object1 b;
    Object *c=&a;
    void(Object::*pFunc)()=&Object::a1;
    cout << sizeof(a) <<endl;
    cout << sizeof(b) <<endl;
    cout << &c->d2 <<endl;
    cout << reinterpret_cast<int*>(&a) <<endl;
    cout << &pFunc <<endl;
    //一般类的地址为其第一个成员变量的地址,而不是第一个成员函数的地址，
    //内存对齐原则使得类的大小根据成员变量的顺序和大小改变
}