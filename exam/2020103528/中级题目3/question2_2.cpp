// 通过一个包含纯虚函数的抽象类示例，说明它的虚函数表和虚指针的情况。
#include <iostream>

class Shape {
public:
    virtual void draw() const = 0; 
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

int main() {
    // 抽象类不能被实例化，但可以通过指针使用
    // 创建一个指向 Circle 对象的指针
    Shape* shapePtr = new Circle();
    
    // 调用虚函数，动态解析到派生类的实现
    shapePtr->draw();
    delete shapePtr;  
    return 0;
}
// 在这个例子中，Shape 是抽象类，因为它包含一个纯虚函数。Circle 是 Shape 的派生类，实现了纯虚函数 draw()。
// 在 main 函数中，创建了一个指向 Circle 对象的 Shape 指针，通过该指针调用虚函数，动态解析到 Circle 类的实现。
// 因为抽象类不能实例化，所以不能创建 Shape 类的对象。
