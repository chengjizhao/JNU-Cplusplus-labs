#include <cmath>
#include <iostream>
/*学号2021102148
初级题目（10-8）=2；
*/

// 抽象基类 Shape
class Shape
{
public:
    // 纯虚函数，用于计算面积
    virtual double area() const = 0;
};

// 圆形类 Circle，从 Shape 派生
class Circle : public Shape
{
private:
    double radius;

public:
    // 构造函数
    Circle(double r) : radius(r) {}

    // 实现基类中的虚函数，计算圆的面积
    double area() const override
    {
        return (3.14) * radius * radius;
    }
};

// 矩形类 Rectangle，从 Shape 派生
class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    // 构造函数
    Rectangle(double l, double w) : length(l), width(w) {}

    // 实现基类中的虚函数，计算矩形的面积
    double area() const override
    {
        return length * width;
    }
};

int main()
{
    // 创建一个 Shape 指针数组，包含一个 Circle 和一个 Rectangle 对象
    Shape *shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    // 计算并输出它们的面积
    for (int i = 0; i < 2; ++i)
    {
        std::cout << "Shape " << i + 1 << " area: " << shapes[i]->area() << std::endl;
    }

    // 释放内存
    for (int i = 0; i < 2; ++i)
    {
        delete shapes[i];
    }

    return 0;
}