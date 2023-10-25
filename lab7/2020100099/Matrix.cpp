#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<int>> data; // 矩阵数据
    int rows; // 行数
    int cols; // 列数

public:
    // 构造函数
    Matrix(int m, int n) : rows(m), cols(n) {
        data.resize(rows, vector<int>(cols));
    }

    // 重载运算符[]，用于获取指定位置的元素
    vector<int>& operator[](int index) {
        return data[index];
    }

    // 重载运算符+
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw runtime_error("矩阵维度不匹配");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    // 重载运算符-
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw runtime_error("矩阵维度不匹配");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    // 重载运算符*
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw runtime_error("矩阵维度不匹配");
        }

        int m = rows;
        int n = other.cols;
        int k = cols;

        Matrix result(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int t = 0; t < k; ++t) {
                    result[i][j] += data[i][t] * other.data[t][j];
                }
            }
        }

        return result;
    }

    // 重载运算符<<，用于输出矩阵
    friend ostream& operator<<(ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << endl;
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
