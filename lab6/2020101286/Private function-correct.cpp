#include <iostream>
class MyClass 
{
private:
    void privateFunc() {
        std::cout << "Private function called" << std::endl;
    }

public:
    void publicFunc() {
        std::cout << "Public function called" << std::endl;
        privateFunc(); // 在类的内部可以直接调用私有成员函数
    }
};

int main() {
    MyClass obj;
    obj.publicFunc(); // 在类的外部可以调用公有成员函数

    // obj.privateFunc();  // 倘若去掉obj.privateFunc()前的//，则代码会提示错误，是无法在类的外部直接调用私有成员函数

    return 0;
}
