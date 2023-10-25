
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
    Shape* shape1 = new Circle(5.0);
    Shape* shape2 = new Rectangle(4.0, 6.0);

    std::cout << "Shape 1 - Circle:" << std::endl;
    std::cout << "Area: " << shape1->getArea() << std::endl;
    std::cout << "Perimeter: " << shape1->getPerimeter() << std::endl;

    std::cout << std::endl;

    std::cout << "Shape 2 - Rectangle:" << std::endl;
    std::cout << "Area: " << shape2->getArea() << std::endl;
    std::cout << "Perimeter: " << shape2->getPerimeter() << std::endl;

    delete shape1;
    delete shape2;

    return 0;
}
