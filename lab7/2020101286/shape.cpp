#include <iostream>
#include <cmath>

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
        return M_PI * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getArea() const override {
        return length * width;
    }

    double getPerimeter() const override {
        return 2 * (length + width);
    }
};

int main() {
    Circle circle(13.0);
    Rectangle rectangle(5.0, 12.0);

    std::cout << "Circle Area: " << circle.getArea() << std::endl;
    std::cout << "Circle Perimeter: " << circle.getPerimeter() << std::endl;

    std::cout << "Rectangle Area: " << rectangle.getArea() << std::endl;
    std::cout << "Rectangle Perimeter: " << rectangle.getPerimeter() << std::endl;

    return 0;
}
