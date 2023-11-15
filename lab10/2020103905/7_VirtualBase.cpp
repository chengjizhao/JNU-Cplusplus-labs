#include <iostream>

class VirtualBase {
public:
    int p;
};

class DerivedWithVirtualBase : virtual public VirtualBase {
public:
    int o;
    void printDerivedWithVirtualBase() {
        std::cout << "DerivedWithVirtualBase: o = " << o << std::endl;
    }
};

int main() {
    DerivedWithVirtualBase derivedVirtualBaseObj;
    derivedVirtualBaseObj.p = 11;
    derivedVirtualBaseObj.o = 12;
    derivedVirtualBaseObj.printDerivedWithVirtualBase();

    return 0;
}
