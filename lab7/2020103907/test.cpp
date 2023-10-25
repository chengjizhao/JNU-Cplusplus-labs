#include <iostream>

// 基类 Shape
class Shape {
public:
    virtual double getArea() const = 0;    // 计算面积的纯虚函数
    virtual double getPerimeter() const = 0; // 计算周长的纯虚函数
};

// 派生类 Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return 3.14159265358979323846 * radius * radius;
    }

    double getPerimeter() const override {
        return 2.0 * 3.14159265358979323846 * radius;
    }
};

// 派生类 Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2.0 * (width + height);
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 5.0);

    std::cout << "Circle Area: " << circle.getArea() << ", Perimeter: " << circle.getPerimeter() << std::endl;
    std::cout << "Rectangle Area: " << rectangle.getArea() << ", Perimeter: " << rectangle.getPerimeter() << std::endl;

    return 0;
}
