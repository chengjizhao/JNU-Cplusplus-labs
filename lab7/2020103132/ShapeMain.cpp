#include"Shape.h"
#include<iostream>

using namespace std;

int main() 
{
    Circle circle(2);
    cout << "area of circle：" << circle.get_area() << endl;
    cout << "perimeter of circle：" << circle.get_perimeter() << endl;

    // 创建一个矩形对象并计算面积和周长
    Rectangle rectangle(2,3);
    cout << "area of rectangle：" << rectangle.get_area() << endl;
    cout << "perimeter of rectangle：" << rectangle.get_perimeter() << endl;

    return 0;
}