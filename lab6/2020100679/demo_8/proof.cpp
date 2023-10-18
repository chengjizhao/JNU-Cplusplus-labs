
#include <iostream>

class MyClass {
private:
    void privateFunction() {
        std::cout << "Private function called." << std::endl;
    }

public:
    void publicFunction() {
        std::cout << "Public function called." << std::endl;
    }
};

int main() {
    MyClass obj;

    // 无法通过函数指针调用私有成员函数
    void (MyClass::*privateFuncPtr)() = &MyClass::privateFunction;
    // privateFuncPtr();  // 编译错误：无法直接调用私有成员函数

    // 可以通过对象的成员函数指针调用私有成员函数
    void (MyClass::*publicFuncPtr)() = &MyClass::publicFunction;
    (obj.*publicFuncPtr)();  // 通过对象的成员函数指针调用公有成员函数

    return 0;
}
