#include <iostream>
#include <vector>

class Matrix {
public:
    Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
        data_.resize(rows, std::vector<double>(cols, 0.0));
    }

    // 设置矩阵元素的公共成员函数
    void setElement(int row, int col, double value) {
        data_[row][col] = value;
    }

    // 重载 + 运算符
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows_, cols_);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                result.data_[i][j] = data_[i][j] + other.data_[i][j];
            }
        }
        return result;
    }

    // 重载 - 运算符
    Matrix operator-(const Matrix& other) const {
        Matrix result(rows_, cols_);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                result.data_[i][j] = data_[i][j] - other.data_[i][j];
            }
        }
        return result;
    }

    // 重载 * 运算符
    Matrix operator*(const Matrix& other) const {
        int resultRows = rows_;
        int resultCols = other.cols_;
        Matrix result(resultRows, resultCols);

        for (int i = 0; i < resultRows; ++i) {
            for (int j = 0; j < resultCols; ++j) {
                double sum = 0.0;
                for (int k = 0; k < cols_; ++k) {
                    sum += data_[i][k] * other.data_[k][j];
                }
                result.data_[i][j] = sum;
            }
        }
        return result;
    }

    // 重载 << 运算符用于直接输出矩阵
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows_; ++i) {
            for (int j = 0; j < matrix.cols_; ++j) {
                os << matrix.data_[i][j] << "\t";
            }
            os << std::endl;
        }
        return os;
    }

private:
    int rows_;
    int cols_;
    std::vector<std::vector<double>> data_;
};

int main() {
    Matrix A(2, 2);
    A.setElement(0, 0, 1);
    A.setElement(0, 1, 2);
    A.setElement(1, 0, 3);
    A.setElement(1, 1, 4);

    Matrix B(2, 2);
    B.setElement(0, 0, 5);
    B.setElement(0, 1, 6);
    B.setElement(1, 0, 7);
    B.setElement(1, 1, 8);

    Matrix C = A + B;
    std::cout << "A + B:\n" << C << std::endl;

    Matrix D = A - B;
    std::cout << "A - B:\n" << D << std::endl;

    Matrix E = A * B;
    std::cout << "A * B:\n" << E << std::endl;

    return 0;
}