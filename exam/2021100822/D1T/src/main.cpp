/*
8.定义一个类Complex，包含私有成员变量real和imaginary，以及友元函数void display(Complex c)用于输出复数。
在main函数中创建两个Complex对象，设置它们的实部和虚部，然后调用display函数显示两个复数的和。
*/

#include <iostream>

using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex(double r, double i)
    {
        real = r;
        imaginary = i;
    }
    friend void display(Complex c);
};

void display(Complex c)
{
    cout << c.real << "+" << c.imaginary << "i" << endl;
}

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    display(c1);
    display(c2);
    return 0;
}