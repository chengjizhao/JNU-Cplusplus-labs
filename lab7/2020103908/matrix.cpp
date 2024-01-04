/*
程序名：matrix.cpp
程序描述：实现矩阵的加减乘，并实现cout 直接输出矩阵。
*/
#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;  // 存储矩阵数据的二维向量

public:
    Matrix(std::vector<std::vector<int>> d) : data(d) {}

    Matrix operator+(const Matrix& other) {
        if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
            throw std::invalid_argument("Matrices must have the same dimensions for addition.");
        }

        Matrix result(data);
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data[0].size(); j++) {
                result.data[i][j] += other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator-(const Matrix& other) {
        if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
            throw std::invalid_argument("Matrices must have the same dimensions for subtraction.");
        }

        Matrix result(data);
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data[0].size(); j++) {
                result.data[i][j] -= other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) {
        if (data[0].size() != other.data.size()) {
            throw std::invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.");
        }

        std::vector<std::vector<int>> result(data.size(), std::vector<int>(other.data[0].size(), 0));
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < other.data[0].size(); j++) {
                for (size_t k = 0; k < data[0].size(); k++) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return Matrix(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (const auto& row : matrix.data) {
            for (const auto& element : row) {
                os << element << ' ';
            }
            os << std::endl;
        }
        return os;
    }
};

int main() {
    std::vector<std::vector<int>> data1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> data2 = {{5, 6}, {7, 8}};

    Matrix matrix1(data1);
    Matrix matrix2(data2);

    Matrix matrixSum = matrix1 + matrix2;
    Matrix matrixDiff = matrix1 - matrix2;
    Matrix matrixProduct = matrix1 * matrix2;

    std::cout << "Matrix 1:" << std::endl << matrix1 << std::endl;
    std::cout << "Matrix 2:" << std::endl << matrix2 << std::endl;
    std::cout << "Matrix Sum:" << std::endl << matrixSum << std::endl;
    std::cout << "Matrix Difference:" << std::endl << matrixDiff << std::endl;
    std::cout << "Matrix Product:" << std::endl << matrixProduct << std::endl;

    return 0;
}
