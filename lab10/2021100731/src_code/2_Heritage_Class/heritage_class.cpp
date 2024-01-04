#include <iostream>

using namespace std;

class BaseClass
{
public:
    int param_Base;
    void Func_Base()
    {
        cout << "BaseFunc is called!" << endl;
    }
};

class SubClass: public BaseClass
{
public:
    int param_Sub;
    void Func_Sub()
    {
        cout << "SubFunc is called!" << endl;
    }
};

typedef void (SubClass::*Funcptr)(void);

int main()
{
    SubClass dummy1;
    int size = sizeof(dummy1);

    int* pClass    = reinterpret_cast<int*>(&dummy1);
    int* pParam1   = &dummy1.param_Base;
    int* pParam2   = &dummy1.param_Sub;
    Funcptr pFunc1 = &SubClass::Func_Base;
    Funcptr pFunc2 = &SubClass::Func_Sub;

    cout << "This is ClassSize    : " << size << endl;
    cout << "This is ClassAddr    : " << pClass << endl;
    cout << "This is ParamAddrBase: " << pParam1 << endl;
    cout << "This is ParamAddrSub : " << pParam2 << endl;
    cout << "This is FuncAddrBase : " << &pFunc1 << endl;
    cout << "This is FuncAddrSub  : " << &pFunc2 << endl;

    (dummy1.*pFunc1)();
    (dummy1.*pFunc2)();

    return 0;
}