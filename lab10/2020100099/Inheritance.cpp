#include <iostream>

class Base {
public:
    int baseData;
    void baseMethod() {
        std::cout << "Base Method" << std::endl;
    }
};

class Derived : public Base {
public:
    int derivedData;
    void derivedMethod() {
        std::cout << "Derived Method" << std::endl;
    }
};

int main() {
    Derived d;

    d.baseData = 10;
    std::cout << "Base Data: " << d.baseData << std::endl;

    d.derivedData = 20;
    std::cout << "Derived Data: " << d.derivedData << std::endl;

    d.baseMethod();
    d.derivedMethod();

    return 0;
}
