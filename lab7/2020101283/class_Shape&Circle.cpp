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
        return 3.14 * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * 3.14 * radius;
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
    Shape* shape1 = new Circle(5.0);
    std::cout << "Circle Area: " << shape1->getArea() << std::endl;
    std::cout << "Circle Perimeter: " << shape1->getPerimeter() << std::endl;

    Shape* shape2 = new Rectangle(4.0, 6.0);
    std::cout << "Rectangle Area: " << shape2->getArea() << std::endl;
    std::cout << "Rectangle Perimeter: " << shape2->getPerimeter() << std::endl;

    delete shape1;
    delete shape2;

    return 0;
}
