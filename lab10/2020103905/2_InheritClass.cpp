#include <iostream>

class Base {
public:
    int y;
    void printBase() {
        std::cout << "Base: y = " << y << std::endl;
    }
};

class Derived : public Base {
public:
    int z;
    void printDerived() {
        std::cout << "Derived: z = " << z << std::endl;
    }
};

int main() {
    Derived derivedObj;
    derivedObj.y = 2;
    derivedObj.z = 3;
    derivedObj.printBase();
    derivedObj.printDerived();

    return 0;
}