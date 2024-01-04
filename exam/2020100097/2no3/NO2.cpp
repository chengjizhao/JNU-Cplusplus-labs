#include <iostream>  
using namespace std;  
  
class Base {  
public:  
    virtual void func() { cout << "Base func" << endl; }  
};  
  
class Der : public Base {  
public:  
    void func() override { cout << "Der func" << endl; }  
};  
  
int main() {  
    Base* basePtr = new Der();  
    basePtr->func();
    delete basePtr;
    return 0;
}