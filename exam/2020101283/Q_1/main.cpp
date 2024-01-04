#include <iostream>
using namespace std;

// 定义类Complex
class Complex
{
private:
    float real;      // 实部
    float imaginary; // 虚部
public:
    Complex() {}

    Complex(float r, float i)
    {
        real = r;
        imaginary = i;
    }

    // 复数相加
    Complex operator+(Complex const &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imaginary = imaginary + obj.imaginary;
        return res;
    }

    // 友元函数用于输出复数
    friend void display(Complex c);
};

// 输出复数的友元函数实现
void display(Complex c)
{
    cout << c.real << "+i" << c.imaginary << endl;
}

// 主函数
int main()
{
    Complex c1(1, 5), c2(6, 3);
    Complex c3 = c1 + c2;
    display(c3);
    return 0;
}
