//在C++中，通过函数指针的方式无法直接规避“只有类的内部函数才能调用私有成员函数”的规则。
//私有成员函数只能在类的内部被访问和调用，无法通过函数指针在类外部直接调用。


#include <iostream>

class MyClass 
{
    private:
    void privateFunction() 
    {
    std::cout << "Private function called" << std::endl;
    }

    public:
    void publicFunction() 
    {
    privateFunction();
    }

    friend void friendFunction(MyClass& obj);
};

void friendFunction(MyClass& obj) 
{
    obj.privateFunction();
}

int main() 
{
    MyClass obj;
    obj.publicFunction(); 
}