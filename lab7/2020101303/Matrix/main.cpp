#include "Matrix.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int numRow_A, numCol_A;
    int numRow_B, numCol_B;
    cout << "输入矩阵A的行、列数:" << endl;
    cin >> numRow_A >> numCol_A;
    cout << "输入矩阵B的行、列数:" << endl;
    cin >> numRow_B >> numCol_B;
    Matrix A(numRow_A, numCol_A);
    Matrix B(numRow_B, numCol_B);
    cout << "输入" << numRow_A << "*" << numCol_A << "矩阵A:" << endl; 
    for (int i=0; i < numRow_A; i++)
    {
        for (int j=0; j < numCol_A; j++)
        {
            double value;
            cin >> value;
            A.set_Matrix(i, j, value);
        }
    }
    cout << "输入" << numRow_B << "*" << numCol_B << "矩阵B:" << endl; 
    for (int i=0; i < numRow_B; i++)
    {
        for (int j=0; j < numCol_B; j++)
        {
            double value;
            cin >> value;
            B.set_Matrix(i, j, value);
        }
    }
    cout << endl;
    Matrix add_C  = A + B;
    cout << "A + B =" << endl << add_C;
    Matrix subtract_C = A - B;
    cout << "A - B =" << endl << subtract_C;
    Matrix  multiply_C = A * B;
    cout << "A * B =" << endl << multiply_C;
    return 0;
}