#include<iostream>
using namespace std;
class Object//带虚函数的类对象，一般类对象
{
public:
    void a1(){};//普通成员函数
    // virtual void b1(){};//虚成员函数
    static void c1(){};//静态成员函数
    int d1;//普通成员属性
    double d2;
    int d3;
};
int main()
{
    Object a;
    Object *c=&a;
    void(Object::*pFunc)()=&Object::a1;
    cout << &c->d2 <<endl;
    cout << reinterpret_cast<int*>(&a) <<endl;
    cout << &pFunc <<endl;
    // cout << "a中虚函数表地址为"  << (int *)(&a) << endl;
    cout << sizeof(a);
}