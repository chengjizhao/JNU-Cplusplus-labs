#include <iostream>
#include "shape.h"

int main()
{
    double s;
    Circle c1;
    cout << " Circle: " << endl;
    c1.set(3);
    c1.getperimeter();
    s = c1.getarea();
    cout << "area=" << s << endl;
    Rectangle r1;
    cout << " Rectangle: " << endl;
    r1.set(4, 5);
    r1.getperimeter();
    s = r1.getarea();
    cout << "area=" << s << endl;
    return 0;
}