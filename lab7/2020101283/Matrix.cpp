#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(const std::vector<std::vector<int>>& matrix) : data(matrix) {}

    Matrix operator+(const Matrix& other) const {
        std::vector<std::vector<int>> result(data.size(), std::vector<int>(data[0].size(), 0));

        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data[0].size(); j++) {
                result[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return Matrix(result);
    }

    Matrix operator-(const Matrix& other) const {
        std::vector<std::vector<int>> result(data.size(), std::vector<int>(data[0].size(), 0));

        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data[0].size(); j++) {
                result[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return Matrix(result);
    }

    Matrix operator*(const Matrix& other) const {
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
                os << element << " ";
            }
            os << std::endl;
        }
        return os;
    }
};

int main() {
    std::vector<std::vector<int>> matrix1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> matrix2 = {{5, 6}, {7, 8}};

    Matrix m1(matrix1);
    Matrix m2(matrix2);

    Matrix addition = m1 + m2;
    std::cout << "Addition:" << std::endl;
    std::cout << addition << std::endl;

    Matrix subtraction = m1 - m2;
    std::cout << "Subtraction:" << std::endl;
    std::cout << subtraction << std::endl;

    Matrix multiplication = m1 * m2;
    std::cout << "Multiplication:" << std::endl;
    std::cout << multiplication << std::endl;

    return 0;
}
