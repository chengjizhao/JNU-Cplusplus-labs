#include <iostream>

using namespace std;

class vFuncClass
{
public:
    int param;
    void normalFunc()
    {
        cout << "normalFunc is called!" << endl;
    }

    virtual void virtualFunc()
    {
        cout << "virtualFunc is called!" << endl;
    }
};

class SubClass: public vFuncClass
{
public:
    int param2;
    void SubFunc()
    {
        cout << "SubFunc is called!" << endl;
    }
};

typedef void (SubClass::*Funcptr)(void);

int main()
{
    SubClass dummy1;
    int size = sizeof(dummy1);

    intptr_t* pClass = (intptr_t*)(&dummy1);/*get vtable address's address*/
    intptr_t* pvtable  = (intptr_t*)(*pClass);/*get vtable address*/
    intptr_t  vFuncAddr= *pvtable;/*get vFunc address*/

    int* pParam1   = &dummy1.param;
    int* pParam2   = &dummy1.param2;
    Funcptr pFunc1 = &SubClass::normalFunc;
    Funcptr pFunc2 = &SubClass::SubFunc;


    cout << "This is ClassSize   : " << size << endl;
    cout << "This is vTableAddr   : " << pvtable << endl;
    cout << "This is ClassAddr    : " << pClass << endl;
    cout << "This is ParamAddrBase: " << pParam1 << endl;
    cout << "This is ParamAddrSub : " << pParam2 << endl;
    cout << "This is FuncAddrSub  : " << &pFunc2 << endl;
    cout << "This is FuncAddrNorm : " << &pFunc1 << endl;
    cout << "This is FuncAddrVirt : " << vFuncAddr << endl;

    (dummy1.*pFunc2)();
    (dummy1.*pFunc1)();
    ((void(*)(void))vFuncAddr)();/*call vFunc*/
    return 0;
}