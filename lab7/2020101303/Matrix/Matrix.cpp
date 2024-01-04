#include "Matrix.h"
#include <vector>
#include <iostream>
using namespace std;

void Matrix::set_Matrix(int numRow, int numCol, double value)
{
    matrix[numRow][numCol] = value;
}

Matrix Matrix::operator+(const Matrix& other) const
{
    if (numRow != other.numRow || numCol != other.numCol)
    {
        cout << "矩阵无法相加!" << endl;
    }
    Matrix result(*this);
    for (int i=0; i < numRow ; i++)
    {
        for (int j=0; j < numCol ; j++)
        {
            result.matrix[i][j] = result.matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const
{
    if (numRow != other.numRow || numCol != other.numCol)
    {
        cout << "矩阵无法相减!" << endl;
    }
    Matrix result(*this);
    for (int i=0; i < numRow ; i++)
    {
        for (int j=0; j < numCol ; j++)
        {
            result.matrix[i][j] = result.matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const
{
    int result_numRow = numRow;
    int result_numCol = other.numCol;
    Matrix result(result_numRow, result_numCol);
    if (numCol != other.numRow)
    {
        cout << "不能实现A*B!（下面的结果为A*B的初始值，非A*B的结果）" << endl;
    }
    else
    {
        for (int i=0; i < result_numRow; i++)
        {
            for (int j=0; j < result_numCol; j++)
            {
                for (int k=0; k < numCol; k++)
                {
                    result.matrix[i][j] = result.matrix[i][j] + matrix[i][k] * other.matrix[k][j];
                }
            }
        }
    }
    return result;
}

ostream& operator<<(ostream& os, const Matrix& other)
{
    for (int i=0; i < other.numRow; i++)
    {
        for (int j=0; j < other.numCol; j++)
        {
            os << other.matrix[i][j] << ' ';
        }
        os << endl;
    }
    return os;
}