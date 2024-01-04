#include <iostream>

class MyClass 
{
private:
    void privateMethod() 
    {
        std::cout << "This is a private method." << std::endl;
    }

public:
    void publicMethod() 
    {
        std::cout << "This is a public method." << std::endl;
    }
};

int main() 
{
    MyClass obj;

    // 试图通过函数指针调用私有成员函数
    void (MyClass::*privateFuncPtr)() = &MyClass::privateMethod;
    (obj.*privateFuncPtr)();  // 编译错误：'void MyClass::privateMethod()' is private within this context

    // 使用对象直接调用私有成员函数
    obj.publicMethod();  // 正确调用公有成员函数

    return 0;
}
