#include "Shape.h"

#include <iostream>
#include <iomanip>

int main()
{
    Circle c0(4);
    Rectangle r0(2, 4);
    std::cout << "Perimeter of circle: " << std::fixed << std::setprecision(2) << c0.get_perimeter() << "\n";
    std::cout << "Area of circle: " << std::fixed << std::setprecision(2) << c0.get_area() << "\n";
    std::cout << "Perimeter of rectangle :" << std::fixed << std::setprecision(2) << r0.get_perimeter() << "\n";
    std::cout << "Area of circle: " << std::fixed << std::setprecision(2) << r0.get_area() << "\n";
    return 0;
}
