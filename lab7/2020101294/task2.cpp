#include <iostream>

// Shape ����
class Shape {
public:
    // ���๹�캯��
    Shape() {}

    // ��������ķ���������������ʵ�֣�
    virtual double calculateArea() {
        return 0.0;
    }

    // �����ܳ��ķ���������������ʵ�֣�
    virtual double calculatePerimeter() {
        return 0.0;
    }
};

// Circle ������
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    // ���ǻ���ķ���
    double calculateArea() override {
        return 3.141592653589793238 * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * 3.141592653589793238 * radius;
    }
};

// Rectangle ������
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    // ���ǻ���ķ���
    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    std::cout << "Circle Area: " << circle.calculateArea() << ", Perimeter: " << circle.calculatePerimeter() << std::endl;
    std::cout << "Rectangle Area: " << rectangle.calculateArea() << ", Perimeter: " << rectangle.calculatePerimeter() << std::endl;

    return 0;
}