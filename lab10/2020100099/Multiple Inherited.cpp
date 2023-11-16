#include <iostream>

class Base1 {
public:
    int baseData1;
};

class Base2 {
public:
    int baseData2;
};

class Derived : public Base1, public Base2 {
public:
    int derivedData;
};

int main() {
    Derived d;

    d.baseData1 = 10;
    std::cout << "Base Data 1: " << d.baseData1 << std::endl;

    d.baseData2 = 20;
    std::cout << "Base Data 2: " << d.baseData2 << std::endl;

    d.derivedData = 30;
    std::cout << "Derived Data: " << d.derivedData << std::endl;

    return 0;
}
