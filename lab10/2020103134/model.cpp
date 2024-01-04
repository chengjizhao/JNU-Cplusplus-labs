#include<iostream>
//一般类对象
class A
{
    public:
    int a;
};
//继承类对象
class B:public A
{
    public:
    int b;
};
//带虚函数的类对象
class C
{
    public:
    virtual void func1(){}
};
//基类有虚函数的子类对象
class D:public C
{
    public:
    virtual void func1(){}
};
//基类有虚函数且子类有自己的更多的虚函数的类对象
class E:public C
{
    public:
    virtual void func2(){}
    virtual void func3(){}
};
//多继承的类对象
class F:public A,public C
{
    public:
    int f;
};
//虚基类的类对象
class vA
{
    public:
    int va;
    virtual ~vA(){}
};
class vB:virtual public vA
{
    public:
    int vb;
    virtual ~vB(){}
};
class vC:virtual public vA
{
    public:
    int vc;
    virtual ~vC(){}
};
class vD:public vB,public vC
{
    public:
    int vd;
    virtual ~vD(){}
};

int main()
{
    using namespace std;
    //一般类对象
    A obja;
    cout<<"一般类对象:"<<sizeof(obja)<<endl;
    //继承类对象
    B objb;
    cout<<"继承类对象:"<<sizeof(objb)<<endl;
    //带虚函数的类对象
    C objc;
    cout<<"带虚函数的类对象:"<<sizeof(objc)<<endl;
    //基类有虚函数的子类对象
    D objd;
    cout<<"基类有虚函数的子类对象:"<<sizeof(objd)<<endl;
    //基类有虚函数且子类有自己的更多的虚函数的类对象
    E obje;
    cout<<"基类有虚函数且子类有自己的更多的虚函数的类对象:"<<sizeof(obje)<<endl;
    //多继承的类对象
    F objf;
    cout<<"多继承的类对象:"<<sizeof(objf)<<endl;
    //虚基类的类对象
    vD objvd;
    cout<<"虚基类的类对象:"<<sizeof(objvd)<<endl;
    return 0;
}