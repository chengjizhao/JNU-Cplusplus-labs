#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "This is Base class." << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "This is Derived class." << std::endl;
    }
};

int main() {
    Base *base = new Derived();
    (*base).print(); 

    void *vtable = base;
    void (*printFunc)(void *) = (void (*)(void *))(*vtable + 1);
    printFunc(base); 

    delete base;
    return 0;
}