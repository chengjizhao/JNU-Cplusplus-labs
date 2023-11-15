#include <iostream>

using namespace std;

class Normal_Class
{
public:
    int param;
    void testFunc()
    {
        cout << "testFunc is called!" << endl;
    }
};

typedef void (Normal_Class::*Funcpointer)(void);

int main()
{   
    Normal_Class dummy1;
    int size = sizeof(dummy1);

    int* pClass = reinterpret_cast<int*>(&dummy1);/*get ClassAddr*/
    int* pParam= &dummy1.param;/*get ParamAddr*/

    Funcpointer pFunc = &Normal_Class::testFunc;/*get FuncAddr*/

    cout << "This is ClassSize: " << size << endl;
    cout << "This is ClassAddr: " << pClass << endl;
    cout << "This is ParamAddr: " << pParam << endl;
    cout << "This is FuncAddr : " << &pFunc << endl;
    (dummy1.*pFunc)();/*Use FuncAddr to call this func*/

    return 0;
}