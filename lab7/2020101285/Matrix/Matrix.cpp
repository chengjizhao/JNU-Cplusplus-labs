#include "Matrix.h"

Matrix::Matrix(std::vector<std::vector<int>> matrixData) {
    data = matrixData;
    rows = matrixData.size();
    cols = matrixData[0].size();
}

Matrix Matrix::operator+(const Matrix& other) {
    std::vector<std::vector<int>> resultData;
    for(int i = 0; i < rows; i++) {
        std::vector<int> row;
        for (int j = 0; j < cols; j++) {
            row.push_back(data[i][j] + other.data[i][j]);
        }
        resultData.push_back(row);
    }
    return Matrix(resultData);
}

Matrix Matrix::operator-(const Matrix& other) {
    std::vector<std::vector<int>> resultData;
    for(int i = 0; i < rows; i++) {
        std::vector<int> row;
        for (int j = 0; j < cols; j++) {
            row.push_back(data[i][j] - other.data[i][j]);
        }
        resultData.push_back(row);
    }
    return Matrix(resultData);
}

Matrix Matrix::operator*(const Matrix& other) {
 std::vector<std::vector<int>> resultData(rows, std::vector<int>(other.cols, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            for (int k = 0; k < cols; k++) {
                resultData[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return Matrix(resultData);
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}