#include <iostream>  
  
class MyClass {  
private:  
    void privateFunction() {  
        std::cout << "This is a private function." << std::endl;  
    }  
  
public:  
    void publicFunction() {  
        privateFunction(); // 调用私有成员函数  
    }  
};  
  
int main() {  
    MyClass obj;  
    obj.publicFunction(); // 通过公有成员函数间接调用私有成员函数  
    return 0;  
}