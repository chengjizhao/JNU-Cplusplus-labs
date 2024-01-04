#include <iostream>
using namespace std;
class Vector {
private:
    double x;
    double y;
public:
    Vector(double x=0, double y=0) : x(x), y(y) {}
    // 重载+运算符
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }
 
    void print() const {
        cout <<x<<","<<y<< endl;
    }
};
 
int main() {
    Vector v1(1,2);
    Vector v2(3,4);
    Vector v3=v1+v2; // 使用重载的+运算符
    v3.print(); // 输出结果 (4, 6)
    return 0;
}