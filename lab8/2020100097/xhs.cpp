#include <iostream>  
#include <vector>  
  
class Base {  
public:  
    virtual void foo() { std::cout << "Base::foo\n"; }  
};  
  
class Derived : public Base {  
public:  
    void foo() override { std::cout << "Derived::foo\n"; }  
};  
  
int main() {  
    std::vector<Base*> bases;  
    for (int i = 0; i < 10; ++i) {  
        bases.push_back(new Derived());  
    }  
    for (auto base : bases) {  
        base->foo(); 
        delete base;  
    }  
    return 0;  
}