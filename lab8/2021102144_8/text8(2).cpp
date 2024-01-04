#include <iostream>
using namespace std;
typedef long long ll;
class A
{
public:
    A() {  }
    virtual void f() { cout << "f()" << endl; }
    virtual void g() { cout << "g()" << endl; }
    virtual ~A() {  }
};
typedef void(*Func)();
int main()
{
    A a1, a2;
    ll* vptr;
    vptr = (ll*)*(ll*)(&a1);
    cout << "a1虚函数表地址: "<< vptr << endl;
    Func f = (Func)(*vptr);
    cout << "a1.f()地址: " << (ll*)f << endl;
    f();
    f = (Func)*(vptr+1);
    cout << "a1.g()地址: " << (ll*)f << endl;
    f();
    vptr = (ll*)*(ll*)(&a2);
    cout << "a2虚函数表地址: " << vptr << endl;
    f = (Func)(*vptr);
    cout << "a2.f()地址: " << (ll*)f << endl;
    f();
    f = (Func)*(vptr + 1);
    cout << "a2.g()地址: " << (ll*)f << endl;
    f();
    return 0;
}//结果是不同对象使用的是同一虚函数表