#include<iostream>
using namespace std;

class Car
{
    public:
    int price;
    virtual void calculatePrice()
    {
        cout << "it is the first function."<< endl;
    }
    virtual void showme()
    {
        cout << "show" << endl;
    }
};

class SUV : public Car
{
    public:
    virtual void calculatePrice()
    {
        cout << "it is the first function in the SUV class." << endl;
    }
};
class Sedan : public Car
{
    public:
    virtual void calculatePrice()
    {
        cout << "it is the first function in the Sedan class. " << endl;
    }
};

using FUNC = void (*)();
int main()
{
    Car *o=new Car();
    SUV *p=new SUV();
    Sedan *q=new Sedan();
    auto *tmp1 =(long long *)o;
    auto *vptr1 = (long long *) (*tmp1);
    FUNC fun1=(FUNC)*(vptr1);
    FUNC fun2=(FUNC)*(vptr1+2);
    FUNC fun3=(FUNC)*(vptr1+4);
    fun1();
    fun2();
    fun3();
    cout << "可见类的虚函数储存在同一个虚数表内，派生类同名的函数储存在基类后两个单位里" << endl ;
    return 0;
}