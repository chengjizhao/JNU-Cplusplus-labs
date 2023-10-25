#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int columns;
    std::vector<std::vector<int>> matrix;

public:
    Matrix(int r, int c) : rows(r), columns(c) {
        matrix.resize(rows, std::vector<int>(columns, 0));
    }

    Matrix(const std::vector<std::vector<int>>& data) : rows(data.size()), columns(data[0].size()), matrix(data) {}

    Matrix& operator=(const std::vector<std::vector<int>>& data) {
        if (data.size() == 0 || data[0].size() == 0) {
            throw std::invalid_argument("Invalid matrix dimensions.");
        }
        
        rows = data.size();
        columns = data[0].size();
        matrix = data;

        return *this;
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            throw std::invalid_argument("Matrix dimensions do not match.");
        }

        Matrix result(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }

        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            throw std::invalid_argument("Matrix dimensions do not match.");
        }

        Matrix result(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (columns != other.rows) {
            throw std::invalid_argument("Matrix dimensions are not compatible for multiplication.");
        }

        int resultRows = rows;
        int resultColumns = other.columns;
        Matrix result(resultRows, resultColumns);

        for (int i = 0; i < resultRows; ++i) {
            for (int j = 0; j < resultColumns; ++j) {
                for (int k = 0; k < columns; ++k) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
        for (const auto& row : mat.matrix) {
            for (int elem : row) {
                os << elem << ' ';
            }
            os << '\n';
        }
        return os;
    }
};

int main() {
    Matrix a(2, 2);
    a = { {1, 2}, {3, 4} };

    Matrix b(2, 2);
    b = { {5, 6}, {7, 8} };

    Matrix sum = a + b;
    Matrix difference = a - b;
    Matrix product = a * b;

    std::cout << "Matrix A:\n" << a << '\n';
    std::cout << "Matrix B:\n" << b << '\n';
    std::cout << "Sum of matrices (A + B):\n" << sum << '\n';
    std::cout << "Difference of matrices (A - B):\n" << difference << '\n';
    std::cout << "Product of matrices (A * B):\n" << product << '\n';

    return 0;
}
