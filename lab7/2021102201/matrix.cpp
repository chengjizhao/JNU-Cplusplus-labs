#include "Matrix.h"

using namespace std;

// ���캯�������ڴ���ָ����С�ľ���
Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(rows, vector<double>(cols, 0.0)) {}

// ��Ա���������þ�����ָ��λ�õ�Ԫ��ֵ
void Matrix::setData(int row, int col, double value)
{
    if (row >= 0 && row < rows_ && col >= 0 && col < cols_)
    {
        data_[row][col] = value;
    }
    else { ; }
}

// ���ؼӷ��������ʵ�־������
Matrix Matrix::operator+(const Matrix& other) const
{

    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            result.data_[i][j] = data_[i][j] + other.data_[i][j];
        }
    }
    return result;
}

// ���ؼ����������ʵ�־������
Matrix Matrix::operator-(const Matrix& other) const
{

    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            result.data_[i][j] = data_[i][j] - other.data_[i][j];
        }
    }
    return result;
}

// ���س˷��������ʵ�־������
Matrix Matrix::operator*(const Matrix& other) const {


    int resultRows = rows_;
    int resultCols = other.cols_;
    Matrix result(resultRows, resultCols);

    for (int i = 0; i < resultRows; i++) {
        for (int j = 0; j < resultCols; j++) {
            for (int k = 0; k < cols_; k++) {
                result.data_[i][j] += data_[i][k] * other.data_[k][j];
            }
        }
    }
    return result;
}

// ��Ԫ�����������������������Ա�ͨ��coutֱ���������
ostream& operator<<(ostream& out, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows_; i++) {
        for (int j = 0; j < matrix.cols_; j++) {
            out << matrix.data_[i][j] << " ";
        }
        out << endl;
    }
    return out;
}