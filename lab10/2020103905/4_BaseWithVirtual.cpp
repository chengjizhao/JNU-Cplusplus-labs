#include <iostream>

class BaseWithVirtual {
public:
    int v;
    virtual void printVirtual() {
        std::cout << "BaseWithVirtual: v = " << v << std::endl;
    }
};

class DerivedWithVirtual : public BaseWithVirtual {
public:
    int u;
};

int main() {
    DerivedWithVirtual derivedVirtualObj;
    derivedVirtualObj.v = 5;
    derivedVirtualObj.printVirtual();

    return 0;
}