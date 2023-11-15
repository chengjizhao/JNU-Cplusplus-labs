#include <iostream>

class VirtualClass {
public:
    int w;
    virtual void printVirtual() {
        std::cout << "VirtualClass: w = " << w << std::endl;
    }
};

int main() {
    VirtualClass virtualObj;
    virtualObj.w = 4;
    virtualObj.printVirtual();

    return 0;
}