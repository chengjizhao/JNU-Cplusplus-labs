#include <iostream>

class Base {
public:
    virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

int main() {
    Base obj1;
    Base obj2;

    std::cout << "Address of vtable for obj1: " << *(reinterpret_cast<void**>(&obj1)) << std::endl;
    std::cout << "Address of vtable for obj2: " << *(reinterpret_cast<void**>(&obj2)) << std::endl;

    return 0;
}
//这段代码定义了一个名为Base的类，并在其中声明了一个虚函数foo()。然后，在main函数中创建了两个Base对象obj1和obj2。
//使用reinterpret_cast将obj1和obj2的地址转换为void指针，并将其解引用打印出来。获取obj1和obj2的虚函数表（vtable）的地址。
//输出结果会显示obj1和obj2的虚函数表的地址。由于obj1和obj2都是Base类的对象，它们共享同一个虚函数表。因此，输出结果应该是一样的。