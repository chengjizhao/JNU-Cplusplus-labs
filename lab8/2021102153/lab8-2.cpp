#include <vector>
#include <string>
#include <iostream>
using namespace std;
class dy//dyw()有重写，dyw1()无重写,dyw2()无重写
{   public:
    virtual void dyw();
    virtual void dyw1();
    virtual void dyw2();
    void(*fp)=nullptr;
};

class dy1:public dy
{
    public:
    virtual void dyw();
};
class dy2:public dy
{
    public:
};
void dy::dyw()
{
    cout << "dy";
}

void dy1::dyw()
{
    cout << "dy1";
}

void dy::dyw1()
{
    cout << "dy_1";
}

void dy::dyw2()
{
}

int main()
{   dy a; dy1 a1;dy2 a2;
    void(dy::*fp1)()=&dy::dyw;
    void(dy::*fp2)()=&dy::dyw1;
    void(dy::*fp3)()=&dy::dyw2;
    void(dy1::*fp4)()=&dy1::dyw;
    void(dy1::*fp5)()=&dy1::dyw1;
    void(dy1::*fp6)()=&dy1::dyw2;
    void(dy2::*fp7)()=&dy2::dyw;
    void(dy2::*fp8)()=&dy2::dyw1;
    void(dy2::*fp9)()=&dy2::dyw2;
    cout << "a中虚函数表地址为"  << (int *)(&a) << endl;
    cout << "a1中虚函数表地址为"  << (int *)(&a1) << endl;
    cout << "a2中虚函数表地址为"  << (int *)(&a2) << endl;
    cout << "a中第一个虚函数指针地址为"  << reinterpret_cast<void*>(a.*fp1) << endl;
    cout << "a中第二个虚函数指针地址为"  << reinterpret_cast<void*>(a.*fp2) << endl;
    cout << "a中第三个虚函数指针地址为"  << reinterpret_cast<void*>(a.*fp3) << endl;
    cout << "a1中第一个虚函数地址为"  << reinterpret_cast<void*>(a1.*fp4) << endl;
    cout << "a1中第二个虚函数地址为"  << reinterpret_cast<void*>(a1.*fp5) << endl;
    cout << "a1中第三个虚函数地址为"  << reinterpret_cast<void*>(a1.*fp6) << endl;
    cout << "a2中第一个虚函数地址为"  << reinterpret_cast<void*>(a2.*fp7) << endl;
    cout << "a2中第二个虚函数地址为"  << reinterpret_cast<void*>(a2.*fp8) << endl;
    cout << "a2中第三个虚函数地址为"  << reinterpret_cast<void*>(a2.*fp9) << endl;
    //结果为：
//a中虚函数表地址为0x61fe10
//a1中虚函数表地址为0x61fe00
//a2中虚函数表地址为0x61fdf0
//a中第一个虚函数指针地址为0x401550
//a中第二个虚函数指针地址为0x40159c
//a中第三个虚函数指针地址为0x4015c2
//a1中第一个虚函数地址为0x401576
//a1中第二个虚函数地址为0x40159c
//a1中第三个虚函数地址为0x4015c2
//a2中第一个虚函数地址为0x401550
//a2中第二个虚函数地址为0x40159c
//a2中第三个虚函数地址为0x4015c2
//可知基类和派生类不共用一个虚函数表，它们各自有自己的虚函数表，一个类的所有对象共用一个虚函数表，当派生类覆盖基类的虚函数时，派生类会改变覆盖的虚函数地址，保留未覆盖的虚函数地址。在这个过程中虚函数地址数量不会改变，只会覆盖虚函数的地址。
}


