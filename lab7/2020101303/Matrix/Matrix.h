#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
using namespace std;

class Matrix
{
    private:
        vector <vector <double> > matrix;
        int numRow;
        int numCol; 
    public:
        Matrix(int numRow, int numCol): numRow(numRow), numCol(numCol), matrix(numRow, vector<double>(numCol, 0.0)) {};
        void set_Matrix(int numRow, int numCol, double value);
        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        friend ostream& operator<<(ostream& os, const Matrix& other);
};
#endif