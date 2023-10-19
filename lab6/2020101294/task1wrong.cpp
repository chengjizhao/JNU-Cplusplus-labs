#include <iostream>

class MyClass {
private:
    void privateFunction() {
        std::cout << "Private Function" << std::endl;
    }

public:
    void callPrivateFunction() {
        privateFunction();
    }
};

int main() {
    MyClass obj;

    // 尝试使用函数指针调用私有成员函数
    void (MyClass::*funcPtr)() = &MyClass::privateFunction;
    // (obj.*funcPtr)(); // 这一行将导致编译错误

    return 0;
}