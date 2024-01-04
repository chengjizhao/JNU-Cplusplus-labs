#include <iostream>  
  
class Base {  
public:  
    virtual void func() { std::cout << "Base func\n"; }  
};  

class Derived : public Base {  
public:  
    void func() override { std::cout << "Derived func\n"; }  
};  
  
int main() {  
    Base* base1 = new Derived();  
    Base* base2 = new Derived();  
      
    if (base1->vptr == base2->vptr) {  
        std::cout << "The vptrs are the same\n";  
    } else {  
        std::cout << "The vptrs are different\n";  
    }  
      
    delete base1;  
    delete base2;  
      
    return 0;  
}