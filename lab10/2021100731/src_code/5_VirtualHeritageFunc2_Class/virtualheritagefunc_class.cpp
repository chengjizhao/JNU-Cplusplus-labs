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
        cout << "vFuncBase is called!" << endl;
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

    virtual void vFuncSub()
    {
        cout << "vFuncSub is called!" << endl;
    }
};

typedef void (SubClass::*Funcptr)(void);

int main()
{
    SubClass dummy1;
    int size = sizeof(dummy1);

    intptr_t* pClass     = (intptr_t*)(&dummy1);/*get vtable address's address*/
    intptr_t* pvtable    = (intptr_t*)(*pClass);/*get vtable address*/
    intptr_t  vFuncAddr1 = *pvtable;/*get vFunc address*/
    intptr_t  vFuncAddr2 = *(pvtable+1);

    int* pParam1   = &dummy1.param;
    int* pParam2   = &dummy1.param2;
    Funcptr pFunc1 = &SubClass::normalFunc;
    Funcptr pFunc2 = &SubClass::SubFunc;

    cout << "This is ClassSize    : " << size << endl;
    cout << "This is vTableAddr   : " << pvtable << endl;
    cout << "This is ClassAddr    : " << pClass << endl;
    cout << "This is ParamAddrBase: " << pParam1 << endl;
    cout << "This is ParamAddrSub : " << pParam2 << endl;
    cout << "This is FuncAddrSub  : " << &pFunc2 << endl;
    cout << "This is FuncAddrNorm : " << &pFunc1 << endl;
    cout << "This is vBaseFuncAddr: " << vFuncAddr1 << endl;
    cout << "This is vBaseFuncAddr: " << vFuncAddr2 << endl;

    (dummy1.*pFunc2)();/*call subFunc*/
    (dummy1.*pFunc1)();/*call baseFunc*/
    ((void(*)(void))vFuncAddr1)();/*call vFuncBase*/
    ((void(*)(void))vFuncAddr2)();/*call vFuncSub*/
    return 0;
}