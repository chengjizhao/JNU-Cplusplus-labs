#include <iostream>
#include <cmath>

class Vector {
private:
    double x, y;

public:
    Vector(double x, double y) : x(x), y(y) {}

    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Vector v1(3, 4);
    Vector v2(1, 2);

    Vector sum = v1 + v2;
    sum.print();

    return 0;
}