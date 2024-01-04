#include <iostream>
#include"shape.h"
using namespace std;

Circle::Circle()
{
 r = 0;
}
double Circle::getarea()
{
 double s;
 s = PI;
 s = s * r * r;
 return s;
}
void Circle:: getperimeter()
{
 double c;
 c = PI;
 c = 2 * c * r;
 cout << "2R =" << 2 * r << endl;//
 cout << "perimeter =" << c << endl;//
}
void Circle::set(int a)
{
 this->r = a;
}
Rectangle::Rectangle()
{
  length = 0;
  width = 0;
}
double Rectangle::getarea()
{
 int s;
 s = length * width;
 return s;
}
void Rectangle:: getperimeter()
{
 cout << "length = " << length << endl;
 cout << "width = " << width << endl;
 cout << "Rectangle perimeter = " << 2 * (length + width) << endl;

}
void Rectangle::set(int a, int b)
{
 length = a;
 width = b;
}





