#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    Matrix(const std::vector<std::vector<int>>& values) : data(values), rows(values.size()), cols(values[0].size()) {}

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Matrix dimensions do not match for addition.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Matrix dimensions do not match for subtraction.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::runtime_error("Matrix dimensions do not match for multiplication.");
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

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << ' ';
            }
            os << '\n';
        }
        return os;
    }
};

int main() {
    std::vector<std::vector<int>> values1 = { {1, 2}, {3, 4} };
    std::vector<std::vector<int>> values2 = { {5, 6}, {7, 8} };

    Matrix matrix1(values1);
    Matrix matrix2(values2);

    Matrix sum = matrix1 + matrix2;
    Matrix difference = matrix1 - matrix2;
    Matrix product = matrix1 * matrix2;

    std::cout << "Matrix 1:\n" << matrix1;
    std::cout << "Matrix 2:\n" << matrix2;

    std::cout << "Sum:\n" << sum;
    std::cout << "Difference:\n" << difference;
    std::cout << "Product:\n" << product;

    return 0;
}