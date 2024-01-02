#include <iostream>  
#include <vector>  
  
class Matrix {  
private:  
    std::vector<std::vector<double>> data;  
    int rows;  
    int cols;  
  
public:  
    Matrix(int r, int c) : rows(r), cols(c) {  
        data.resize(r, std::vector<double>(c, 0.0));  
    }  
  
    int getRows() const { return rows; }  
    int getCols() const { return cols; }  
  
    double& operator()(int i, int j) { return data[i][j]; }  
    const double& operator()(int i, int j) const { return data[i][j]; }  
  
    Matrix operator+(const Matrix& other) const {  
        if (cols != other.cols || rows != other.rows) {  
            throw std::runtime_error("Matrix sizes are not compatible for addition");  
        }  
        Matrix result(rows, cols);  
        for (int i = 0; i < rows; ++i) {  
            for (int j = 0; j < cols; ++j) {  
                result(i, j) = data[i][j] + other.data[i][j];  
            }  
        }  
        return result;  
    }  
  
    Matrix operator-(const Matrix& other) const {  
        if (cols != other.cols || rows != other.rows) {  
            throw std::runtime_error("Matrix sizes are not compatible for subtraction");  
        }  
        Matrix result(rows, cols);  
        for (int i = 0; i < rows; ++i) {  
            for (int j = 0; j < cols; ++j) {  
                result(i, j) = data[i][j] - other.data[i][j];  
            }  
        }  
        return result;  
    }  
  
    Matrix operator*(const Matrix& other) const {  
        if (cols != other.rows) {  
            throw std::runtime_error("Matrix sizes are not compatible for multiplication");  
        }  
        Matrix result(rows, other.cols);  
        for (int i = 0; i < rows; ++i) {  
            for (int j = 0; j < other.cols; ++j) {  
                for (int k = 0; k < cols; ++k) {  
                    result(i, j) += data[i][k] * other.data[k][j];  
                }  
            }  
        }  
        return result;  
    }  
};  
  
std::ostream& operator<<(std::ostream& os, const Matrix& mat) {  
    for (int i = 0; i < mat.getRows(); ++i) {  
        for (int j = 0; j < mat.getCols(); ++j) {  
            os << mat(i, j) << ' ';  
        }  
        os << '\n';  
    }  
    return os;  
}