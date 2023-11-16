#include <iostream>
using namespace std;

// General Objects
class GeneralObject {
    int x;
    float y;
    char z;
};

// Inheritance Objects
class BaseObject {
    int x;
};

class DerivedObject : public BaseObject {
    float y;
};

// Objects with Virtual Functions
class VirtualObject {
    int x;
    virtual void foo() = 0;
};

class DerivedVirtualObject : public VirtualObject {
    float y;
    void foo() override {}
};

// Subclasses with Virtual Functions
class BaseObjectWithVirtualFunctions {
    int x;
    virtual void foo() = 0;
};

class DerivedObjectWithVirtualFunctions : public BaseObjectWithVirtualFunctions {
    float y;
    void foo() override {}
};

// Subclasses with More Virtual Functions
class BaseObjectWithMoreVirtualFunctions {
    int x;
    virtual void foo() = 0;
    virtual void bar() = 0;
};

class DerivedObjectWithMoreVirtualFunctions : public BaseObjectWithMoreVirtualFunctions {
    float y;
    void foo() override {}
    void bar() override {}
};

// Multiple Inheritance Objects
class BaseObject1 {
    int x;
};

class BaseObject2 {
    float y;
};

class DerivedObject : public BaseObject1, public BaseObject2 {
    char z;
};

// Virtual Base Classes
class BaseObject {
    int x;
};

class VirtualBaseObject : virtual public BaseObject {
    float y;
};

class DerivedObject : public VirtualBaseObject {
    char z;
};

int main() {
    cout << "GeneralObject size: " << sizeof(GeneralObject) << endl;
    cout << "InheritanceObject size: " << sizeof(DerivedObject) << endl;
    cout << "Objects with Virtual Functions size: " << sizeof(DerivedVirtualObject) << endl;
    cout << "Subclasses with Virtual Functions size: " << sizeof(DerivedObjectWithVirtualFunctions) << endl;
    cout << "Subclasses with More Virtual Functions size: " << sizeof(DerivedObjectWithMoreVirtualFunctions) << endl;
    cout << "Multiple Inheritance Objects size: " << sizeof(DerivedObject) << endl;
    cout << "Virtual Base Classes size: " << sizeof(DerivedObject) << endl;
    return 0;
}
