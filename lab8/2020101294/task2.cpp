#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Derived class" << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    Base* basePtr = &baseObj;
    Base* derivedPtr = &derivedObj;

    // �麯������
    basePtr->print();    // ��� "Base class"
    derivedPtr->print(); // ��� "Derived class"

    // �麯�����ַ
    void* baseVTable = *(void**)(&baseObj);
    void* derivedVTable = *(void**)(&derivedObj);

    std::cout << "Base VTable Address: " << baseVTable << std::endl;
    std::cout << "Derived VTable Address: " << derivedVTable << std::endl;

    return 0;
}