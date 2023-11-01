#include <iostream>

class Base {
public:
    virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

int main() {
    Base obj1;
    Base obj2;

    std::cout << "Address of vtable for obj1: " << *(reinterpret_cast<void**>(&obj1)) << std::endl;
    std::cout << "Address of vtable for obj2: " << *(reinterpret_cast<void**>(&obj2)) << std::endl;

    return 0;
}