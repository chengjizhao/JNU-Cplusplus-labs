#include <iostream>  
#include <vector>  
using namespace std;
class Matrix {  
private:  
    vector<vector<int>> data;  
    int rows;  
    int cols;  
  
public:  
    Matrix(int r, int c) : rows(r), cols(c) {  
        data.resize(r, vector<int>(c));  
    }  
  
      // 重载运算符[]，用于获取指定位置的元素
    vector<int>& operator[](int index) {
        return data[index];
    }
    
    int& operator()(int row, int col) {  
        return data[row][col];  
    }  
  
    const int& operator()(int row, int col) const {  
        return data[row][col];  
    }  
  
    Matrix operator+(const Matrix& other) const {  
        Matrix result(rows, cols);  
        for (int i = 0; i < rows; ++i) {  
            for (int j = 0; j < cols; ++j) {  
                result(i, j) = (*this)(i, j) + other(i, j);  
            }  
        }  
        return result;  
    }  
  
    Matrix operator-(const Matrix& other) const {  
        Matrix result(rows, cols);  
        for (int i = 0; i < rows; ++i) {  
            for (int j = 0; j < cols; ++j) {  
                result(i, j) = (*this)(i, j) - other(i, j);  
            }  
        }  
        return result;  
    }  
  
    Matrix operator*(const Matrix& other) const {  
        Matrix result(rows, other.cols);  
        for (int i = 0; i < rows; ++i) {  
            for (int j = 0; j < other.cols; ++j) {  
                int sum = 0;  
                for (int k = 0; k < cols; ++k) {  
                    sum += (*this)(i, k) * other(k, j);  
                }  
                result(i, j) = sum;  
            }  
        }  
        return result;  
    }  
  
    friend std::ostream& operator<<(ostream& os, const Matrix& matrix) {  
        for (int i = 0; i < matrix.rows; ++i) {  
            for (int j = 0; j < matrix.cols; ++j) {  
                os << matrix(i, j) << ' ';  
            }  
            os << '\n';  
        }  
        return os;  
    }  
};
int main() {
    Matrix A(2, 2);
    Matrix B(2, 2);

    // 初始化矩阵A和B
    A[0][0] = 0; A[0][1] = 1; 
    A[1][0] = 1; A[1][1] = 2; 

    B[0][0] = 0; B[0][1] = 2;
    B[1][0] = 3; B[1][1] = 1;
  

    // 输出矩阵A和B
    cout << "矩阵A：" << endl;
    cout << A << endl;

    cout << "矩阵B：" << endl;
    cout << B << endl;

    try {
        // 计算矩阵加法、减法、乘法
        Matrix C = A + B;
        Matrix D = A - B;
        Matrix E = A * B;

        // 输出结果矩阵
        cout << "矩阵C（A + B）：" << endl;
        cout << C << endl;

        cout << "矩阵D（A - B）：" << endl;
        cout << D << endl;

        cout << "矩阵E（A * B）：" << endl;
        cout << E << endl;
    } catch (const runtime_error& e) {
        cout << "发生错误：" << e.what() << endl;
    }

    return 0;
}