#include <iostream>

class MyClass {
private:
    int privateData = 42;

public:
    void publicFunction() {
        std::cout << "Public Function: " << privateData << std::endl;
    }
};

int main() {
    MyClass obj;

    // 使用函数指针调用公有成员函数
    void (MyClass::*funcPtr)() = &MyClass::publicFunction;
    (obj.*funcPtr)();

    return 0;
}