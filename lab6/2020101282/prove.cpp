#include <iostream>

class MyClass {
private:
    void privateFunction() {
        std::cout << "Private function called.\n";
    }

public:
    void callPrivateFunction(void (MyClass::funcPtr)()) {
        (this->funcPtr)();  // 调用私有成员函数
    }
};

int main() {
    MyClass obj;
    
// 尝试通过函数指针调用私有成员函数（错误示例）
// void (MyClass::funcPtr)() = &MyClass::privateFunction;  // 编译错误，无法访问私有成员函数
// obj.callPrivateFunction(funcPtr);  // 编译错误，无法访问私有成员函数

// 正确调用私有成员函数的方式
obj.callPrivateFunction(&MyClass::privateFunction);

return 0;
}

