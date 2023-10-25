#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(const std::vector<std::vector<int>>& d): data(d) {}

    Matrix operator+(const Matrix& other) const {
        std::vector<std::vector<int>> result;
        for (size_t i = 0; i < data.size(); ++i) {
            std::vector<int> row;
            for (size_t j = 0; j < data[i].size(); ++j) {
                int sum = data[i][j] + other.data[i][j];
                row.push_back(sum);
            }
            result.push_back(row);
        }
        return Matrix(result);
    }

    Matrix operator-(const Matrix& other) const {
        std::vector<std::vector<int>> result;
        for (size_t i = 0; i < data.size(); ++i) {
            std::vector<int> row;
            for (size_t j = 0; j < data[i].size(); ++j) {
                int diff = data[i][j] - other.data[i][j];
                row.push_back(diff);
            }
            result.push_back(row);
        }
        return Matrix(result);
    }

    Matrix operator*(const Matrix& other) const {
        std::vector<std::vector<int>> result;
        size_t m = data.size();
        size_t n = other.data[0].size();
        size_t p = other.data.size();
        for (size_t i = 0; i < m; ++i) {
            std::vector<int> row;
            for (size_t j = 0; j < n; ++j) {
                int sum = 0;
                for (size_t k = 0; k < p; ++k) {
                    sum += data[i][k] * other.data[k][j];
                }
                row.push_back(sum);
            }
            result.push_back(row);
        }
        return Matrix(result);
    }

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
    // 创建两个矩阵
    Matrix matrix1({{1, 2, 3}, {4, 5, 6}});
    Matrix matrix2({{7, 8, 9}, {10, 11, 12}});

    // 进行加法、减法和乘法运算并输出结果
    Matrix sum = matrix1 + matrix2;
    Matrix diff = matrix1 - matrix2;
    Matrix product = matrix1 * matrix2;

    std::cout << "Sum:" << std::endl;
    std::cout << sum << std::endl;

    std::cout << "Difference:" << std::endl;
    std::cout << diff << std::endl;

    std::cout << "Product:" << std::endl;
    std::cout << product << std::endl;

    return 0;
}
