#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

using namespace std;

class Matrix {
public:
    Matrix(int rows, int cols);
    void setData(int row, int col, double value);
    //重载某种运算符需要用 “operator+ - * /” 的方式
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    // 友元函数：重载输出流运算符，以便通过cout直接输出矩阵
    friend ostream& operator<<(ostream& out, const Matrix& matrix);

private:
    int rows_; // 矩阵的行数
    int cols_; // 矩阵的列数
    vector<vector<double>> data_; // 存储矩阵数据的二维向量
};

#endif