#include <iostream>

using namespace std;

class Base1
{
public:
    int bParam1;
    void bFunc1()
    {
        cout << "bFunc1 is called!" << endl;
    }
};

class Base2
{
public:
    int bParam2;
    void bFunc2()
    {
        cout << "bFunc2 is called!" << endl;
    }
};

class Sub: public Base1, public Base2
{
public:
    int sParam;
    void sFunc()
    {
        cout << "sFunc is called!" << endl;
    }
};



typedef void (Sub::*Funcptr)(void);

int main()
{
    Sub dummy1;
    int size = sizeof(dummy1);

    int* pClass    = reinterpret_cast<int*>(&dummy1);
    int* pParam1   = &dummy1.bParam1;
    int* pParam2   = &dummy1.bParam2;
    int* pParam3   = &dummy1.sParam;
    Funcptr pFunc1 = &Sub::bFunc1;
    Funcptr pFunc2 = &Sub::bFunc2;
    Funcptr pFunc3 = &Sub::sFunc;  

    cout << "This is ClassSize     : " << size << endl;
    cout << "This is ClassAddr     : " << pClass << endl;
    cout << "This is ParamAddrBase1: " << pParam1 << endl;
    cout << "This is ParamAddrBase2: " << pParam2 << endl;
    cout << "This is ParamAddrSub  : " << pParam3 << endl;
    cout << "This is FuncAddrBase1 : " << &pFunc1 << endl;
    cout << "This is FuncAddrBase2 : " << &pFunc2 << endl;
    cout << "This is FuncAddrSub   : " << &pFunc3 << endl;

    
    (dummy1.*pFunc1)();/*call baseFunc1*/
    (dummy1.*pFunc2)();/*call baseFunc2*/
    (dummy1.*pFunc3)();/*call subFunc*/
    
    return 0;
}