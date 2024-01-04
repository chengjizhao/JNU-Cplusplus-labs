#include <iostream>
using namespace std;

class AbstractClass {
public:
    virtual void step1() = 0;
    virtual void step2() = 0;

    void algorithm() {
        step1();
        step2();
    }
};

class ConcreteClassA : public AbstractClass {
public:
    void step1() override {
        cout << "ConcreteClassA: Step 1" << endl;
    }

    void step2() override {
        cout << "ConcreteClassA: Step 2" << endl;
    }
};

class ConcreteClassB : public AbstractClass {
public:
    void step1() override {
        cout << "ConcreteClassB: Step 1" << endl;
    }

    void step2() override {
        cout << "ConcreteClassB: Step 2" << endl;
    }
};

int main() {
    AbstractClass* objA = new ConcreteClassA();
    objA->algorithm();

    AbstractClass* objB = new ConcreteClassB();
    objB->algorithm();

    delete objA;
    delete objB;

    return 0;
}
