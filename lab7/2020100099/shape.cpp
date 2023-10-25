#include <iostream>

using namespace std;

// 基类 Shape
class Shape {
public:
    virtual double getArea() const = 0; // 计算面积的纯虚函数
    virtual double getPerimeter() const = 0; // 计算周长的纯虚函数
};

// 派生类 Circle
class Circle : public Shape {
private:
    double radius; // 半径

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

// 派生类 Rectangle
class Rectangle : public Shape {
private:
    double width; // 宽度
    double height; // 高度

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2 * (width + height);
    }
};

int main() {
    // 创建一个圆对象并计算面积和周长
    Circle circle(5.0);
    cout << "圆的面积：" << circle.getArea() << endl;
    cout << "圆的周长：" << circle.getPerimeter() << endl;

    // 创建一个矩形对象并计算面积和周长
    Rectangle rectangle(4.0, 6.0);
    cout << "矩形的面积：" << rectangle.getArea() << endl;
    cout << "矩形的周长：" << rectangle.getPerimeter() << endl;

    return 0;
}
