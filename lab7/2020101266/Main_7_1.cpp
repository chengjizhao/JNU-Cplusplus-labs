#include <iostream>  
#include <vector>  

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    // 构造函数  
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, std::vector<double>(cols));
    }

    // 矩阵加法  
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Matrix sizes do not match for addition");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // 矩阵乘法  
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::runtime_error("Matrix sizes do not match for multiplication");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // 获取矩阵的元素值  
    double& operator()(int i, int j) {
        return data[i][j];
    }
};

int main() {
    Matrix m1(2, 2);  // 2x2矩阵  
    m1(0, 0) = 1;       // 设置元素值，下标从0开始计数  
    m1(0, 1) = 2;        // 设置元素值，下标从0开始计数  
    m1(1, 0) = 3;         // 设置元素值，下标从0开始计数  
    m1(1, 1) = 4;          // 设置元素值，下标从0开始计数  
    Matrix m2(2, 2);       // 另一个2x2矩阵，初始化为0矩阵  
    m2(0, 0) = 5;           // 设置元素值，下标从0开始计数  
    m2(0, 1) = 6;            // 设置元素值，下标从0开始计数  
    m2(1, 0) = 7;             // 设置元素值，下标从0开始计数  
    m2(1, 1) = 8;              // 设置元素值，下标从0开始计数  
    Matrix sum = m1 + m2;       // 矩阵加法  
    Matrix product = m1 * m2;    // 矩阵乘法  
    // ... 可以继续进行其他操作和输出结果 ...  
    return 0;
}