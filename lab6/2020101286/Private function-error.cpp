#include <iostream>

class MyClass {
private:
    void privateFunc() {
        std::cout << "Private function called" << std::endl;
    }

public:
    void publicFunc() {
        std::cout << "Public function called" << std::endl;
    }
};

int main() {
    MyClass obj;
    obj.publicFunc(); // 在类的外部可以调用公有成员函数

    obj.privateFunc();  // 错误！无法在类的外部直接调用私有成员函数

    return 0;
}