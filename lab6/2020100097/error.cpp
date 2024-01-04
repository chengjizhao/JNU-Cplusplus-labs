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
    void (MyClass::*ptr)() = &MyClass::privateFunction; // 错误：私有成员函数的地址不能直接获取  
    (obj.*ptr)(); // 错误：不能直接通过函数指针调用私有成员函数  
    return 0;  
}