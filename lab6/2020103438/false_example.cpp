#include <iostream>

class MyClass
{
private:
    void privateFunction()
    {
        std::cout << "Private Function called." << std::endl;
    }

public:
    void publicFunction()
    {
        std::cout << "Public Function called." << std::endl;
    }
};

int main()
{
    MyClass obj;

    // 定义函数指针并尝试调用私有成员函数
    void (MyClass::*functionPtr)() = &MyClass::privateFunction;
    // 尝试通过函数指针调用私有成员函数
    //(obj.*functionPtr)(); // 这行代码无法访问私有成员函数

    return 0;
}