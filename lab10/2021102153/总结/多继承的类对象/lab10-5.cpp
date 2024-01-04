#include<iostream>
using namespace std;
class Object//带虚函数的类对象，一般类对象
{
public:
    int d1;//普通成员属性
    double d2;
    int d3;
};
class Objects
{
public:
int c;
};

class Object4 : public Objects,public Object//多继承的类对象(非菱形继承)
{
    public:
int b;
};
int main()
{   
    Object4 a;
    Object4 *b=&a;
    cout << sizeof(a) << endl;
    cout << &b->c << endl;
    cout << &b->d1 << endl;
    cout << &b->d2 << endl;
    cout << &b->d3 << endl;
    cout << &b->b << endl;
    //多继承类对象则是根据继承顺序，先父类再子类
    //结果为40
    //0x61fdf0
//0x61fdf8
//0x61fe00
//0x61fe08
}