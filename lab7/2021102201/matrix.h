#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

using namespace std;

class Matrix {
public:
    Matrix(int rows, int cols);
    void setData(int row, int col, double value);
    //����ĳ���������Ҫ�� ��operator+ - * /�� �ķ�ʽ
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    // ��Ԫ�����������������������Ա�ͨ��coutֱ���������
    friend ostream& operator<<(ostream& out, const Matrix& matrix);

private:
    int rows_; // ���������
    int cols_; // ���������
    vector<vector<double>> data_; // �洢�������ݵĶ�ά����
};

#endif