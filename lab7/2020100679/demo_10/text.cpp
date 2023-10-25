#include <iostream>

class Shape {
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

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
        return 2 * (width + height);
    }
};

int main() {
    // 创建圆形对象并计算面积和周长
    Circle circle(5.0);
    double circleArea = circle.getArea();
    double circlePerimeter = circle.getPerimeter();
    std::cout << "Circle area: " << circleArea << std::endl;
    std::cout << "Circle perimeter: " << circlePerimeter << std::endl;

    // 创建矩形对象并计算面积和周长
    Rectangle rectangle(4.0, 6.0);
    double rectangleArea = rectangle.getArea();
    double rectanglePerimeter = rectangle.getPerimeter();
    std::cout << "Rectangle area: " << rectangleArea << std::endl;
    std::cout << "Rectangle perimeter: " << rectanglePerimeter << std::endl;

    return 0;
}
