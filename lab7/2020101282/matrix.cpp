#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data; // 二维向量表示矩阵

public:
    Matrix() {}
    Matrix(const std::vector<std::vector<int>>& input) : data(input) {}

    // 重载加法运算符
    Matrix operator+(const Matrix& other) const {
        if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
            std::cerr << "Matrix dimensions do not match for addition." << std::endl;
            return Matrix();
        }

        Matrix result;
        for (size_t i = 0; i < data.size(); ++i) {
            std::vector<int> row;
            for (size_t j = 0; j < data[0].size(); ++j) {
                row.push_back(data[i][j] + other.data[i][j]);
            }
            result.data.push_back(row);
        }

        return result;
    }

    // 重载减法运算符
    Matrix operator-(const Matrix& other) const {
        if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
            std::cerr << "Matrix dimensions do not match for subtraction." << std::endl;
            return Matrix();
        }

        Matrix result;
        for (size_t i = 0; i < data.size(); ++i) {
            std::vector<int> row;
            for (size_t j = 0; j < data[0].size(); ++j) {
                row.push_back(data[i][j] - other.data[i][j]);
            }
            result.data.push_back(row);
        }

        return result;
    }

    // 重载乘法运算符
    Matrix operator*(const Matrix& other) const {
        if (data[0].size() != other.data.size()) {
            std::cerr << "Matrix dimensions are not suitable for multiplication." << std::endl;
            return Matrix();
        }

        Matrix result;
        for (size_t i = 0; i < data.size(); ++i) {
            std::vector<int> row;
            for (size_t j = 0; j < other.data[0].size(); ++j) {
                int sum = 0;
                for (size_t k = 0; k < data[0].size(); ++k) {
                    sum += data[i][k] * other.data[k][j];
                }
                row.push_back(sum);
            }
            result.data.push_back(row);
        }

        return result;
    }

    // 重载流输出运算符
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < matrix.data.size(); ++i) {
            for (size_t j = 0; j < matrix.data[i].size(); ++j) {
                os << matrix.data[i][j] << ' ';
            }
            os << std::endl;
        }
        return os;
    }
};

int main() {
    // 创建矩阵示例
    std::vector<std::vector<int>> data1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> data2 = {{7, 8}, {9, 10}, {11, 12}};

    Matrix matrix1(data1);
    Matrix matrix2(data2);

    // 执行矩阵加法、减法、乘法，并输出结果
    Matrix result_add = matrix1 + matrix2;
    std::cout << "Addition result:\n" << result_add << std::endl;

    Matrix result_sub = matrix1 - matrix2;
    std::cout << "Subtraction result:\n" << result_sub << std::endl;

    Matrix result_mul = matrix1 * matrix2;
    std::cout << "Multiplication result:\n" << result_mul << std::endl;

    return 0;
}
