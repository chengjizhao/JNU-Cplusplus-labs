#include <iostream>

class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing a shape..." << std::endl;
    }
};

class triangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a triangle..." << std::endl;
    }
};

int main() {
    Shape* shapePtr = new triangle ();
    shapePtr->draw();
    return 0;
}





//在这个示例中，Circle 是 Shape 的派生类，并重写了 draw() 方法。
//在 main 函数中，使用基类指针 Shape* 指向一个 Circle 对象。
//当调用 draw() 方法时，由于 draw() 是虚函数，会根据实际对象的类型动态地调用 Circle 类中的 draw() 方法。
//这个过程依赖于虚指针的存在，它指向了正确的虚函数表，以便在运行时正确调用相应的函数。