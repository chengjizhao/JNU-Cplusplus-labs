#include <iostream>

using namespace std;

class Base
{
    public:
        virtual void foo() { cout << "Base::foo()" << endl; }
};

int main() {
    Base* obj1 = new Base();
    Base* obj2 = new Base();

    // 访问虚函数表指针
    uintptr_t* vptr1 = reinterpret_cast<uintptr_t*>(obj1);
    uintptr_t* vptr2 = reinterpret_cast<uintptr_t*>(obj2);

    // 输出虚函数表地址
    cout << "vtable address of obj1: " << vptr1[0] << endl;
    cout << "vtable address of obj2: " << vptr2[0] << endl;

    delete obj1;
    delete obj2;

    return 0;
}
