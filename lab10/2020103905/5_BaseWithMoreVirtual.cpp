#include <iostream>

class BaseWithMoreVirtual {
public:
    int t;
    virtual void printVirtual() {
        std::cout << "BaseWithMoreVirtual: t = " << t << std::endl;
    }
};

class DerivedWithMoreVirtual : public BaseWithMoreVirtual {
public:
    int s;
    virtual void printMoreVirtual() {
        std::cout << "DerivedWithMoreVirtual: s = " << s << std::endl;
    }
};

int main() {
    DerivedWithMoreVirtual derivedMoreVirtualObj;
    derivedMoreVirtualObj.t = 6;
    derivedMoreVirtualObj.s = 7;
    derivedMoreVirtualObj.printVirtual();
    derivedMoreVirtualObj.printMoreVirtual();

    return 0;
}