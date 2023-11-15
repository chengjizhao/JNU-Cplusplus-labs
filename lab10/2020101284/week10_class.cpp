#include <iostream>

class Base {
public:
    int baseVar;

    virtual void baseFunc() {
        std::cout << "Base::baseFunc()" << std::endl;
    }
};

class Derived : public Base {
public:
    int derivedVar;

    virtual void derivedFunc() {
        std::cout << "Derived::derivedFunc()" << std::endl;
    }
};

class MoreDerived : public Derived {
public:
    int moreDerivedVar;

    virtual void moreDerivedFunc() {
        std::cout << "MoreDerived::moreDerivedFunc()" << std::endl;
    }
};

class AnotherBase {
public:
    int anotherBaseVar;

    virtual void anotherBaseFunc() {
        std::cout << "AnotherBase::anotherBaseFunc()" << std::endl;
    }
};

class MultipleInheritance : public Base, public AnotherBase {
public:
    int multipleInheritanceVar;

    virtual void multipleInheritanceFunc() {
        std::cout << "MultipleInheritance::multipleInheritanceFunc()" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;
    MoreDerived moreDerivedObj;
    MultipleInheritance multipleInheritanceObj;

    std::cout << "Size of Base object: " << sizeof(baseObj) << std::endl;
    std::cout << "Size of Derived object: " << sizeof(derivedObj) << std::endl;
    std::cout << "Size of MoreDerived object: " << sizeof(moreDerivedObj) << std::endl;
    std::cout << "Size of MultipleInheritance object: " << sizeof(multipleInheritanceObj) << std::endl;

    return 0;
}