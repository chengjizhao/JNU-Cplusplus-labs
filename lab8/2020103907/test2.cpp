#include <iostream>

using namespace std;
class Base {
public:
    virtual void someFunction() {
        cout << "Base::someFunction()" << endl;
    }
};

class Derived : public Base {
public:
    void someFunction() override {
        cout << "Derived::someFunction()" << endl;
    }
};

int main() {
    Base baseObj;
    Base baseObj1;
    Derived derivedObj;

    // 获取虚函数表指针
    uintptr_t* baseVptr = *reinterpret_cast<uintptr_t**>(&baseObj);
    uintptr_t* baseVptr1 = *reinterpret_cast<uintptr_t**>(&baseObj1);
    uintptr_t* derivedVptr = *reinterpret_cast<uintptr_t**>(&derivedObj);
    
    // 输出虚函数表指针
    cout << "Base object vptr: " << baseVptr << endl;
    cout << "Base object vptr: " << baseVptr1 << endl;
    cout << "Derived object vptr: " << derivedVptr << endl;
    
    return 0;
}
