#include <iostream>
using namespace std;

class Shape
{
public:
    int l_, w_, r_;
};

class Circle : public Shape
{
public:
    Circle(int r) { r_ = r; };

    float S()
    {
        return (r_ * r_ * 3.14);
    }
    float C()
    {
        return (2 * 3.14 * r_);
    }
};
class Rectangle : Shape
{
public:
    Rectangle(int l, int w)
    {
        l_ = l;
        w_ = w;
    };

    int S()
    {
        return l_ * w_;
    }
    int C()
    {
        return 2 * (l_ + w_);
    }
};

int main()
{
    Circle circle1(1);
    cout << "circle1的面积是：" << circle1.S() << endl;
    cout << "circle1的周长是：" << circle1.C() << endl;
    Rectangle rectangle1(2, 1);
    cout << "rectangle1的面积是：" << rectangle1.S() << endl;
    cout << "rectangle1的周长是：" << rectangle1.C() << endl;
    return 0;
}