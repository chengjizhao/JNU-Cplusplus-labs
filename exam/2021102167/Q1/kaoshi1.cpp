#include <iostream>

class Vector {
private:
    int  x;
    int  y;
public:
    Vector(float x, float y) : x(x), y(y) {}

    Vector operator+(const Vector& v) {
        return Vector(this->x + v.x, this->y + v.y);
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

int main() {
    Vector v1(123,456);
    Vector v2(321,654);

    Vector v3 = v1 + v2;

    std::cout << "v1 + v2 = (" << v3.getX() << ", " << v3.getY() << ")" << std::endl;

    return 0;
}