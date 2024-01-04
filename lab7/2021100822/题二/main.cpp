#include <iostream>
#include "Matrix.h"

int main() {
    // 创建两个矩阵对象
    Matrix a(2, 2);
    Matrix b(2, 2);

    a.setData(0, 0, 1);
    a.setData(0, 1, 2);
    a.setData(1, 0, 3);
    a.setData(1, 1, 4);

    b.setData(0, 0, 5);
    b.setData(0, 1, 6);
    b.setData(1, 0, 7);
    b.setData(1, 1, 8);

    // 加法
    Matrix c_add = a + b;
    std::cout << "Matrix c_add (a + b):" << std::endl;
    std::cout << c_add;

    // 减法
    Matrix c_subtract = a - b;
    std::cout << "Matrix c_subtract (a - b):" << std::endl;
    std::cout << c_subtract;

    // 乘法
    Matrix c_multiply = a * b;
    std::cout << "Matrix c_multiply (a * b):" << std::endl;
    std::cout << c_multiply;

    return 0;
}
