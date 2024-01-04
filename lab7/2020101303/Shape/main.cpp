#include "Shape.h"
#include <iostream>
using namespace std;

int main()
{
    double radius, length, width;
    cout << "输入圆的半径:";
    cin >> radius;
    cout << "输入矩形的长和宽: ";
    cin >> length >> width;
    Circle circle(radius);
    Rectangle rectangle(length, width);
    cout << "圆的周长: " << circle.calculate_Perimerter() << endl;
    cout << "圆的面积: " << circle.calculate_Area() << endl;
    cout << "矩形的周长: " << rectangle.calculate_Perimerter() << endl;
    cout << "矩形的面积: " << rectangle.calculate_Area() << endl;
    return 0;
}