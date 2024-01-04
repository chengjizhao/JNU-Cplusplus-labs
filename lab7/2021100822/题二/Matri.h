#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
public:
    // 构造函数，用于创建指定大小的矩阵
    Matrix(int rows, int cols);

    // 成员函数：设置矩阵中指定位置的元素值
    void setData(int row, int col, double value);

    // 重载加法运算符，实现矩阵相加
    Matrix operator+(const Matrix& other) const;

    // 重载减法运算符，实现矩阵相减
    Matrix operator-(const Matrix& other) const;

    // 重载乘法运算符，实现矩阵相乘
    Matrix operator*(const Matrix& other) const;

    // 友元函数：重载输出流运算符，以便通过cout直接输出矩阵
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

private:
    int rows_; // 矩阵的行数
    int cols_; // 矩阵的列数
    std::vector<std::vector<double>> data_; // 存储矩阵数据的二维向量
};

#endif
