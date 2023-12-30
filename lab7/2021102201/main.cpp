#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    // 创建两个矩阵对象
    Matrix a(2, 2);
    Matrix b(2, 2);

    a.setData(0, 0, 1);
    a.setData(0, 1, 2);
    a.setData(1, 0, 3);
    a.setData(1, 1, 4);

    b.setData(0, 0, 2);
    b.setData(0, 1, 3);
    b.setData(1, 0, 4);
    b.setData(1, 1, 5);
    
    Matrix c_add = a + b;
    cout << "a + b =" << endl;
    cout << c_add << endl;

    Matrix c_subtract = a - b;
    cout << "a - b =" << endl;
    cout << c_subtract << endl;

    Matrix c_multiply = a * b;
    cout << "a * b =" << endl;
    cout << c_multiply << endl;

    return 0;
}