#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;
class Matrix {
private:
    vector<vector<double>> data;
    int rows;
    int cols;

public:
    // 构造函数
    Matrix(int rows, int cols);

    // 运算符重载
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    // 输出运算符重载
    friend ostream& operator<<(ostream& os, const Matrix& matrix);

    // 获取矩阵行数和列数
    int getRows() const;
    int getCols() const;

    // 获取矩阵中的元素
    double& operator()(int rows, int col);
    const double& operator()(int rows, int col) const;
};

#endif
