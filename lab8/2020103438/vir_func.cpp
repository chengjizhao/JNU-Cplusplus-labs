#include <iostream>
using namespace std;

class Base
{
public:
    virtual void foo()
    {
        cout << "Base::foo()" << endl;
    }
};

int main()
{
    Base obj1;
    Base obj2;

    cout << "Address of vtable for obj1: " << *(reinterpret_cast<void **>(&obj1)) << endl;
    cout << "Address of vtable for obj2: " << *(reinterpret_cast<void **>(&obj2)) << endl;

    return 0;
}