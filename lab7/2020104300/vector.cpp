#include <iostream>  
#include <vector>  
  
class Matrix {  
public:  
    Matrix(int rows, int cols) : rows_(rows), cols_(cols) {  
        data_.resize(rows, std::vector<int>(cols));  
    }  
  
    int& operator()(int row, int col) {  
        return data_[row][col];  
    }  
  
    const int& operator()(int row, int col) const {  
        return data_[row][col];  
    }  
  
    Matrix operator+(const Matrix& other) const {  
        Matrix result(rows_, cols_);  
        for (int i = 0; i < rows_; ++i) {  
            for (int j = 0; j < cols_; ++j) {  
                result(i, j) = (*this)(i, j) + other(i, j);  
            }  
        }  
        return result;  
    }  
  
    Matrix operator-(const Matrix& other) const {  
        Matrix result(rows_, cols_);  
        for (int i = 0; i < rows_; ++i) {  
            for (int j = 0; j < cols_; ++j) {  
                result(i, j) = (*this)(i, j) - other(i, j);  
            }  
        }  
        return result;  
    }  
  
    Matrix operator*(const Matrix& other) const {  
        Matrix result(rows_, other.cols_);  
        for (int i = 0; i < rows_; ++i) {  
            for (int j = 0; j < other.cols_; ++j) {  
                int sum = 0;  
                for (int k = 0; k < cols_; ++k) {  
                    sum += (*this)(i, k) * other(k, j);  
                }  
                result(i, j) = sum;  
            }  
        }  
        return result;  
    }  
  
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);  
  
private:  
    int rows_;  
    int cols_;  
    std::vector<std::vector<int>> data_;  
};  
  
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {  
    for (int i = 0; i < matrix.rows_; ++i) {  
        for (int j = 0; j < matrix.cols_; ++j) {  
            os << matrix(i, j) << " ";  
        }  
        os << std::endl;  
    }  
    return os;  
}
