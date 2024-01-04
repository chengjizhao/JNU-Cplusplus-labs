#include<iostream>
using namespace std;
class Object//带虚函数的类对象，一般类对象
{
public:
    void a1(){};//普通成员函数
    static void c1(){};//静态成员函数
    //double l;加上则为32
    //int l;加上则为24
    int d1;//普通成员属性
    double d2;
    int d3;
    // double l;加上则为32
    // int l;加上则为24
};

class Object1:public Object//继承类对象
{
    double l;
};

class Object2:public Object//继承类对象
{
int l;
};

int main()
{
    Object a;
    Object1 b;
    Object2 b1;
    void(Object1::*pFunc)()=&Object1::a1;
    Object1 *c=&b;
    cout << sizeof(a) <<endl;
    cout << sizeof(b) <<endl;
    cout << sizeof(b1) <<endl;
    cout << &pFunc <<endl;
    cout << &c->d1 <<endl;
    cout << &c->d2 <<endl;
    cout << reinterpret_cast<int*>(&b) <<endl;
    //输出结果为24，32，32可见继承类对象的内存对齐是先对父类进行分配
}