#include <iostream>

class MyClass {
private:
    void privateFunction() {
        std::cout << "Private function called." << std::endl;
    }
};

int main() {
    MyClass obj;
    
    // 尝试通过函数指针调用私有成员函数
    void (MyClass::*funcPtr)() = &MyClass::privateFunction;  // 定义函数指针并赋值为私有成员函数
    (obj.*funcPtr)();  // 尝试通过函数指针调用私有成员函数，这会导致编译错误
    
    return 0;
}
