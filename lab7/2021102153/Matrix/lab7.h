#ifndef  _LAB7_H_
#define  _LAB7_H_
#include <vector>
#include <iostream>
using namespace std;
class Matrix
{
    public:
    vector<vector<int>>vec;
    friend ostream& operator<<(ostream& out,Matrix &p);
    int r;//行
    int c;//列
    Matrix(int a,int b);
    Matrix operator+ (const Matrix& m);
    Matrix operator- (const Matrix& m);
    Matrix operator* (const Matrix& m);
};
#endif