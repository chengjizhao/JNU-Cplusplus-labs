/*
在C++中，函数指针通过类型转换规则，绕过访问控制（即访问私有成员函数）。
这违背了类的封装性原则，因此不应该通过函数指针的方式直接调用私有成员函数。
然而，我们可以通过使用友元函数或者成员函数来间接调用私有成员函数。
*/
#include <iostream>

class MyClass {
private:
    void privateFunction() {
        std::cout << "Private function called!" << std::endl;
    }

    friend void friendFunction(MyClass& obj);
public:
    void publicFunction() {
        std::cout << "Public function called!" << std::endl;
    }

    void callPrivateFunction() {
        privateFunction(); // 成员函数可以直接调用私有成员函数
    }
};

void friendFunction(MyClass& obj) {
    obj.privateFunction(); // 友元函数可以直接调用私有成员函数
}

int main() {
    // 错误示例，通过外部函数指针调用私有成员函数
    typedef void (MyClass::*PrivateFunctionPtr)(); // 定义一个指向私有成员函数的指针类型
    PrivateFunctionPtr pointer = &MyClass::privateFunction; // 将私有成员函数的指针赋给外部函数指针
    MyClass obj;
    (obj.*pointer)(); // 编译错误，无法访问私有成员函数

    //正确示例
    obj.callPrivateFunction(); // 通过成员函数间接调用
    friendFunction(obj); // 通过友元函数间接调用

    return 0;
}