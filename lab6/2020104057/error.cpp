#include <iostream>

class MyClass {
private:
    void privateFunc() {
        std::cout << "Private function called" << std::endl;
    }

public:
    void publicFunc() {
        std::cout << "Public function called" << std::endl;
    }
};

int main() 
{
    MyClass obj;
    obj.publicFunc(); 
    
    // 在类的外部可以调用公有成员函数，无法在类的外部直接调用私有成员函数，C++禁止直接获取非静态成员方法的指针

	  // return SampleClass::private_method; // 编译错误  

    obj.privateFunc();  

    return 0;
}