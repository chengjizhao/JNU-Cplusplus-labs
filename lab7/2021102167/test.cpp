#include <iostream>
using namespace std;
class Shape {
protected:
    double x, y; // 对于不同的形状，x和y表示不同的含义
public:
    Shape(double a, double b) : x(a), y(b) {}
    virtual double getArea() = 0; // 纯虚函数，用于计算面积
    virtual double getPerimeter() = 0; // 纯虚函数，用于计算周长
};

class Circle : public Shape {
private:
    double r; // 圆的半径
public:
    Circle(double a, double b, double c) : Shape(a, b), r(c) {}
    double getArea() { return 3.14 * r * r; }
    double getPerimeter() { return 2 * 3.14 * r; }
};

class Rectangle : public Shape {
private:
    double l, w; // 矩形的长和宽
public:
    Rectangle(double a, double b, double c, double d) : Shape(a, b), l(c), w(d) {}
    double getArea() { return l * w; }
    double getPerimeter() { return 2 * (l + w); }
};
int main() {
    Circle c(0, 0, 5);
    Rectangle r(0, 0, 3, 4);
    cout << "Circle area: " << c.getArea() << endl;
    cout << "Circle perimeter: " << c.getPerimeter() << endl;

    cout << "Rectangle area: " << r.getArea() << endl;
    cout << "Rectangle perimeter: " << r.getPerimeter() << endl;
    return 0;
}