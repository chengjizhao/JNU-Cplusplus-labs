//请解释C++中虚函数表的概念以及编译器如何为每个包含虚函数的类生成该表的。
//为了证明虚函数表的存在，你会如何修改一个类并通过实例访问虚函数表中的内容？
//说明在继承中虚函数表是如何工作的，派生类是如何与基类共享虚函数表的。
//并用UML图画出一种设计模式，它使用了虚函数来达成目标。

#include <iostream>

using namespace std;

class Shape {
public:
    virtual void display() {
        cout << "Shape" << endl;
    }
};

class Line : public Shape {
public:
    virtual void display() {
        cout << "Line" << endl;
    }
};

int main() {
    Line line;
    uintptr_t *vptr = reinterpret_cast<uintptr_t *>(&line);
    uintptr_t *vtable = reinterpret_cast<uintptr_t *>(*vptr);

    typedef void (*FuncPtr)();
    FuncPtr func = reinterpret_cast<FuncPtr>(vtable[0]);
    func();

    return 0;
}