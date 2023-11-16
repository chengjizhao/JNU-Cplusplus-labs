#include <iostream>

class Base {
public:
    int baseData;
    virtual void virtualMethod() {
        std::cout << "Base Virtual Method" << std::endl;
    }
};

class Derived : public Base {
public:
    int derivedData;
    void virtualMethod() override {
        std::cout << "Derived Virtual Method" << std::endl;
    }
};

int main() {
    Derived d;

    d.baseData = 10;
    std::cout << "Base Data: " << d.baseData << std::endl;

    d.derivedData = 20;
    std::cout << "Derived Data: " << d.derivedData << std::endl;

    d.virtualMethod();

    return 0;
}
