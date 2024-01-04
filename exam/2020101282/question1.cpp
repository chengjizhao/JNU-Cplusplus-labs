#include<iostream>

//定义类Complex
class Complex {
private:
    double real;
    double imaginary;

public:
    // 构造函数
    Complex(double r, double i) : real(r), imaginary(i) {}

    // 友元函数声明
    friend void display(Complex c);
    
    // 获取实部和虚部的成员函数
    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    // 运算符重载(用于复数相加)
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
};

// 友元函数定义(用于输出复数)
void display(Complex c) {
    std::cout << "Complex Number: " << c.real << " + " << c.imaginary << "i" << std::endl;
}

int main() {
    // 创建两个Complex对象，设置它们的实部和虚部
    Complex complex1(2.5, 3.0);
    Complex complex2(4.0, 1.5);

    // 计算两个复数的和
    Complex sum = complex1 + complex2;

    // 显示两个复数的和
    display(sum);

    return 0;
}
