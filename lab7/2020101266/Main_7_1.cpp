#include <iostream>  
#include <vector>  

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    // ���캯��  
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, std::vector<double>(cols));
    }

    // ����ӷ�  
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Matrix sizes do not match for addition");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // ����˷�  
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::runtime_error("Matrix sizes do not match for multiplication");
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

    // ��ȡ�����Ԫ��ֵ  
    double& operator()(int i, int j) {
        return data[i][j];
    }
};

int main() {
    Matrix m1(2, 2);  // 2x2����  
    m1(0, 0) = 1;       // ����Ԫ��ֵ���±��0��ʼ����  
    m1(0, 1) = 2;        // ����Ԫ��ֵ���±��0��ʼ����  
    m1(1, 0) = 3;         // ����Ԫ��ֵ���±��0��ʼ����  
    m1(1, 1) = 4;          // ����Ԫ��ֵ���±��0��ʼ����  
    Matrix m2(2, 2);       // ��һ��2x2���󣬳�ʼ��Ϊ0����  
    m2(0, 0) = 5;           // ����Ԫ��ֵ���±��0��ʼ����  
    m2(0, 1) = 6;            // ����Ԫ��ֵ���±��0��ʼ����  
    m2(1, 0) = 7;             // ����Ԫ��ֵ���±��0��ʼ����  
    m2(1, 1) = 8;              // ����Ԫ��ֵ���±��0��ʼ����  
    Matrix sum = m1 + m2;       // ����ӷ�  
    Matrix product = m1 * m2;    // ����˷�  
    // ... ���Լ����������������������� ...  
    return 0;
}