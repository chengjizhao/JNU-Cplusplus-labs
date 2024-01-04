#include <iostream>

class Base {
public:
    int baseData;
};

class VirtualBase : virtual public Base {
public:
    int virtualBaseData;
};

class Derived : virtual public Base {
public:
    int derivedData;
};

class MostDerived : public VirtualBase, public Derived {
public:
    int mostDerivedData;
};

int main() {
    MostDerived md;

    md.baseData = 10;
    std::cout << "Base Data: " << md.baseData << std::endl;

    md.virtualBaseData = 20;
    std::cout << "Virtual Base Data: " << md.virtualBaseData << std::endl;

    md.derivedData = 30;
    std::cout << "Derived Data: " << md.derivedData << std::endl;

    md.mostDerivedData = 40;
    std::cout << "Most Derived Data: " << md.mostDerivedData << std::endl;

    return 0;
}
