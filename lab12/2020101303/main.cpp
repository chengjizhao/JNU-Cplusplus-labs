#include "Shape.h"
#include <iostream>
using namespace std;
int main()
{
    Circle c(1);
    Rectangle r(1, 2);
    std::cout << "Perimeter of circle: " << c.get_perimeter() << endl;
    std::cout << "Area of circle: "  << c.get_area() << endl;
    std::cout << "Perimeter of rectangle :"  << r.get_perimeter() << endl;
    std::cout << "Area of circle: "  << r.get_area() << endl;
    return 0;
}