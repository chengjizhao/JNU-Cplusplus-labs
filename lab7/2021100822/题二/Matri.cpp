#include "Matrix.h"

// 构造函数，用于创建指定大小的矩阵
Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(rows, std::vector<double>(cols, 0.0)) {}

// 成员函数：设置矩阵中指定位置的元素值
void Matrix::setData(int row, int col, double value) {
    if (row >= 0 && row < rows_ && col >= 0 && col < cols_) {
        data_[row][col] = value;
    }
    else {
    }
}

// 重载加法运算符，实现矩阵相加
Matrix Matrix::operator+(const Matrix& other) const {
  
    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            result.data_[i][j] = data_[i][j] + other.data_[i][j];
        }
    }
    return result;
}

// 重载减法运算符，实现矩阵相减
Matrix Matrix::operator-(const Matrix& other) const {

    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            result.data_[i][j] = data_[i][j] - other.data_[i][j];
        }
    }
    return result;
}

// 重载乘法运算符，实现矩阵相乘
Matrix Matrix::operator*(const Matrix& other) const {


    int resultRows = rows_;
    int resultCols = other.cols_;
    Matrix result(resultRows, resultCols);

    for (int i = 0; i < resultRows; i++) {
        for (int j = 0; j < resultCols; j++) {
            for (int k = 0; k < cols_; k++) {
                result.data_[i][j] += data_[i][k] * other.data_[k][j];
            }
        }
    }
    return result;
}

// 友元函数：重载输出流运算符，以便通过cout直接输出矩阵
std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows_; i++) {
        for (int j = 0; j < matrix.cols_; j++) {
            out << matrix.data_[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}
