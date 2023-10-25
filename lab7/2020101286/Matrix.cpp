#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data; // 二维向量存储矩阵数据

public:
    Matrix(const std::vector<std::vector<int>>& matrixData) : data(matrixData) {}

    // 重载运算符+
    Matrix operator+(const Matrix& other) const {
        int rows = data.size();
        int cols = data[0].size();
        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    // 重载运算符-
    Matrix operator-(const Matrix& other) const {
        int rows = data.size();
        int cols = data[0].size();
        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    // 重载运算符*
    Matrix operator*(const Matrix& other) const {
        int m = data.size();
        int n = other.data[0].size();
        int p = other.data.size();
        Matrix result(m, n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < p; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    // 重载运算符<<，实现直接输出矩阵
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (const auto& row : matrix.data) {
            for (const auto& element : row) {
                os << element << " ";
            }
            os << std::endl;
        }

        return os;
    }
};

int main() {
    Matrix A({{1, 2}, {3, 4}});
    Matrix B({{5, 6}, {7, 8}});

    Matrix C = A + B;
    std::cout << "A + B: \n" << C << std::endl;

    Matrix D = A - B;
    std::cout << "A - B: \n" << D << std::endl;

    Matrix E = A * B;
    std::cout << "A * B: \n" << E << std::endl;

    return 0;
}
