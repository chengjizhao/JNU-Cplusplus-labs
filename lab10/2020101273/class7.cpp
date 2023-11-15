#include "class7.h"

int main()
{    
    //1
    General g;
    cout << "1.一般内对象：对象和变量地址一致" << endl;
    cout << "general对象地址：" << &g << endl;
    cout << "变量a地址：" << &g.a << endl;
    cout << endl;
    //2
    Son s;
    cout << "2.继承内对象：子类对象中基类变量下方是子类变量" << endl;
    cout << "son对象地址：" << &s << endl;
    cout << "基类变量a地址：" << &s.a << endl;
    cout << "子类变量b地址：" << &s.b << endl;
    cout << endl;
    //3    
    Base b;
    cout << "3.带虚函数的类对象：首地址是对象指针指向虚函数表指针vptr" << endl;
    cout << "base对象地址：" << &b << endl;
    cout << "变量c地址：" << &b.c << endl;

    Base* ptrb = new Base();
    auto *tmp = (long long*)ptrb;
    auto *vptrgram = (long long*)(*tmp);
    cout << "base虚函数表指针地址：" << tmp << endl; 
    cout << "base虚函数表地址：" << vptrgram << endl; 
    FUNC fun1 = (FUNC)*vptrgram;
    fun1();
    cout << endl;
    //4
    cout << "4.基类有虚函数的子类对象：子类对象的虚函数表有基类的虚函数" << endl;
    Dve* e = new Dve();
    auto *tmp1 = (long long*)e;
    auto *vptrgram1 = (long long*)(*tmp1);
    cout << "dve虚函数表地址：" << vptrgram1 << endl;
    FUNC fun2 = (FUNC)*vptrgram1;
    fun2();//指针调用
    Dve dve;//对象调用
    dve.print();
    cout << endl;
    //5
    cout << "5.基类有虚函数且子类有自己的更多的虚函数的类对象：" ;
    cout << "子类虚函数表内基类虚函数的重写和新增虚函数" << endl;
    Diver* d = new Diver();
    auto *tmp2 = (long long*)d;
    auto *vptrgram2 = (long long*)(*tmp2);
    cout << "diver虚函数表地址：" << vptrgram2 << endl;

    FUNC fun3 = (FUNC)*vptrgram2;
    FUNC fun4 = (FUNC)*(vptrgram2+1);
    fun3();
    fun4();
    cout << endl;
    //6
    Base1 p1;Base2 p2;Driver q;
    cout << "6.多继承的类对象:子类有两个基类的变量" << endl;
    cout << "Base1的变量地址f1:" << &p1.f1 << endl;
    cout << "Base2的变量地址f2:" << &p2.f2 << endl;
    cout << "继承子类的变量地址f1/f2/many:" << &q.f1 \
    << "/" << &q.f2 << "/" << &q.many << endl;
    cout << endl;
    //7
    B tf1; B1 tf2;
    cout << "7.虚基类的类对象:" << endl;
    cout << "基类对象地址" << &tf1 << endl;
    cout << "子类变量地址" << &tf2.ib << " " << &tf2.ib1 << endl;
    cout << "子类对象地址" << &tf2 << endl;
    B1* vbptr = new B1();
    auto *mmp = (long long*)vbptr;
    auto *upgt = (long long*)(*mmp);
    //cout << "虚基类地址：" << upgt << endl;
    FUNC fun5 = (FUNC)*upgt;
    fun5();
    FUNC fun6 = (FUNC)*(upgt+1);
    fun6();
}