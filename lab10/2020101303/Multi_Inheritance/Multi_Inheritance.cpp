#include <iostream>
using namespace std;

class Base1 
{
    public:
        int base1;
};

class Base2 
{
    public:
        double base2;
};

class Derived : public Base1, public Base2 
{
    public:
        char derived;
};

int main() {
    Derived obj;
    cout << "Size of Derived: " << sizeof(obj) << " bytes" << endl;
    int *base1_ptr = &obj.base1;
    double *base2_ptr = &obj.base2;
    char *derived_ptr = &obj.derived;
    cout << "base1: " << reinterpret_cast<void*>(base1_ptr) << endl;
    cout << "base2: " << reinterpret_cast<void*>(base2_ptr) << endl;
    cout << "derived: " << reinterpret_cast<void*>(derived_ptr) << endl;
    Base1 obj_1;
    return 0;
}