#include <iostream>
#include "Matrix.h"

int main() {
    Matrix A(2, 3);
    Matrix B(2, 3);

    // 初始化矩阵A和B

    // 执行加法
    Matrix C = A + B;
    std::cout << "A + B:\n" << C;

    // 执行减法
    Matrix D = A - B;
    std::cout << "A - B:\n" << D;

    // 执行乘法
    Matrix E(3, 2);
    // 初始化矩阵E
    Matrix F = A * E;
    std::cout << "A * E:\n" << F;

    return 0;
}
