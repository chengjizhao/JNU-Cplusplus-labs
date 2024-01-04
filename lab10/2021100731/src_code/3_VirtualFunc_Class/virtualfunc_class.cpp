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

typedef void (vFuncClass::*Funcptr)(void);

int main()
{
    vFuncClass dummy1;
    int size = sizeof(dummy1);

    intptr_t* pClass = (intptr_t*)(&dummy1);/*get vtable address's address*/
    intptr_t* pvtable  = (intptr_t*)(*pClass);/*get vtable address*/
    intptr_t  vFuncAddr= *pvtable;/*get vFunc address*/

    int* pParam   = &dummy1.param;
    Funcptr pFunc1 = &vFuncClass::normalFunc;

    cout << "This is vTableSize   : " << size << endl;
    cout << "This is vTableAddr   : " << pvtable << endl;
    cout << "This is ClassAddr    : " << pClass << endl;
    cout << "This is ParamAddr    : " << pParam << endl;
    cout << "This is FuncAddrNorm : " << &pFunc1 << endl;
    cout << "This is FuncAddrVirt : " << vFuncAddr << endl;

    (dummy1.*pFunc1)();
    ((void(*)(void))vFuncAddr)();/*call vFunc*/
    return 0;
}