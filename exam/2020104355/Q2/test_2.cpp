#include <iostream>

class AbstractClass {
public:
    virtual void pureVirtualFunction() = 0;
    virtual void normalVirtualFunction() {
        std::cout << "AbstractClass::normalVirtualFunction()" << std::endl;
    }
};

int main() {
    // 无法实例化抽象类，下面这行代码将导致编译错误
    // AbstractClass obj;

    // 但可以通过指针或引用使用抽象类
    AbstractClass* ptr = nullptr;
    AbstractClass& ref = *ptr;  // 这是合法的，但需要注意确保指针不为空

    return 0;
}
