#include <iostream>
using namespace std;
class Vector {
    private:
       double x;
       double y;
    public:
       Vector(double x_, double y_) : x(x_), y(y_) {}
       Vector operator+(const Vector& other) const
       {
        return Vector(x + other.x, y + other.y);
        }
    double getX() const 
    {
        return x;
    }
    double getY() const 
    {
        return y;
    }
};

int main() 
{
    Vector a(1.0, 2.0);
    Vector b(3.0, 4.0);

    Vector sum = a + b;

    cout << "a = (" << a.getX() << ", " << a.getY() << ")" << endl;
    cout << "b = (" << b.getX() << ", " << b.getY() << ")" << endl;
    cout << "Sum = (" << sum.getX() << ", " << sum.getY() << ")" << endl;

    return 0;
}
