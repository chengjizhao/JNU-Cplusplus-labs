#include <iostream>

class MyClass
{
private:
    void privateFunction()
    {
        std::cout << "Private Function called." << std::endl;
    }

    friend void friendFunction(MyClass &obj);

public:
    void publicFunction()
    {
        std::cout << "Public Function called." << std::endl;
        privateFunction(); // 可以在公有成员函数中直接调用私有成员函数
    }
};

void friendFunction(MyClass &obj)
{
    std::cout << "Friend Function called." << std::endl;
    obj.privateFunction(); // 友元函数可以直接访问私有成员函数
}

int main()
{
    MyClass obj;
    obj.publicFunction(); // 通过公有成员函数调用私有成员函数
    friendFunction(obj);  // 通过友元函数调用私有成员函数

    return 0;
}