#include <iostream>

// 抽象基类 AbstractBase
class AbstractBase {
public:
    // 纯虚函数
    virtual void pureVirtualFunction() const = 0;
};

// 派生类 DerivedClass
class DerivedClass : public AbstractBase {
public:
    // 实现纯虚函数
    void pureVirtualFunction() const override {
        std::cout << "DerivedClass::pureVirtualFunction()" << std::endl;
    }
};

int main() {
    // 尝试实例化抽象基类，会导致编译错误
    // AbstractBase obj;  // Error: cannot instantiate abstract class

    // 创建派生类对象
    DerivedClass derivedObj;

    // 调用虚函数
    derivedObj.pureVirtualFunction();

    return 0;
}
