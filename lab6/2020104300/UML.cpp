#include <iostream>  
  
class MyClass {  
public:  
    void publicMethod() {  
        std::cout << "This is a public method." << std::endl;  
    }  
  
protected:  
    void protectedMethod() {  
        std::cout << "This is a protected method." << std::endl;  
    }  
  
private:  
    int privateVar;  
};  
  
int main() {  
    MyClass obj;  
    obj.publicMethod();  
    obj.protectedMethod();  
  
    return 0;  
}
