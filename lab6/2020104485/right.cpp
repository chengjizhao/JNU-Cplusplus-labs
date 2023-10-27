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
        privateMethod();  // 在公有成员函数中直接调用私有成员函数
    }
};

int main() 
{
    MyClass obj;
    obj.publicMethod();

    return 0;
}
