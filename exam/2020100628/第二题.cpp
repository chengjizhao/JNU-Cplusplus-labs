#include <iostream>

class AbstractClass {
public:
    virtual void pureVirtualFunction() const = 0;
    virtual void nonVirtualFunction() const {
        std::cout << "Non-virtual function in AbstractClass." << std::endl;
    }

    virtual ~AbstractClass() = default;
};

class DerivedClass : public AbstractClass {
public:
    void pureVirtualFunction() const override {
        std::cout << "Pure virtual function implementation in DerivedClass." << std::endl;
    }
};

int main() {
    DerivedClass obj;

    AbstractClass* ptr = &obj;

    ptr->pureVirtualFunction();
    ptr->nonVirtualFunction();

    return 0;
}