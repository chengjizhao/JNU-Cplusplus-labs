//虚析构函数可以在用父类的指针指向子类的引用时，如果父类的析构函数非虚函数，删除该引用时将不会调用子类的虚构函数。
#include<iostream>
using namespace std;
class A
{
    public:
    virtual ~A () //在实例中如果把virtual去掉，那么当delete一个new B时，~B()将不会被调用。
    {cout << "class A "<< endl ;} 
};

class B : public A
{
    public:
    ~B()
    {cout << "class B"<< endl ;} 
};

int main()
{
    A *p=new B;
    delete p ;
}