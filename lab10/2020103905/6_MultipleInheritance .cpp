#include <iostream>

class GeneralClass {
public:
    int x;
    void print() {
        std::cout << "GeneralClass: x = " << x << std::endl;
    }
};

class Base {
public:
    int y;
    void printBase() {
        std::cout << "Base: y = " << y << std::endl;
    }
};

class MultipleInheritance : public Base, public GeneralClass {
public:
    int q;
    void printMultiple() {
        std::cout << "MultipleInheritance: q = " << q << std::endl;
    }
};

int main() {
    MultipleInheritance multipleObj;
    multipleObj.y = 8;
    multipleObj.x = 9;
    multipleObj.q = 10;
    multipleObj.printBase();
    multipleObj.print();
    multipleObj.printMultiple();

    return 0;
}