#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;  
    virtual ~Shape() {}  
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length* width;
    }
};

int main() {
    Shape* shapes[2];
    Circle circle(3);
    Rectangle rectangle(2, 1);
    shapes[0] = &circle;
    shapes[1] = &rectangle;
    for (int i = 0; i < 2; ++i) {
        cout << "Area of shape " << i + 1 << ": " << shapes[i]->area() << endl;
    }
    return 0;
}