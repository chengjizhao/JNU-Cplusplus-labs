#include <iostream>
#include <vector>
using namespace std;
class Matrix
{
    public:
        Matrix(vector<vector<int>> d) : c(d){}
        Matrix operator+(Matrix& other) {
            vector<int> e;
            vector<vector<int>> f;
            for (int i = 0; i < c.size(); i ++)
            {
                for (int j = 0; j < c[i].size(); j ++)
                {
                    e.push_back(c[i][j] + other.c[i][j]);
                }
                f.push_back(e);
                e.clear();
            }
            return Matrix(f);
        }
        Matrix operator-(Matrix& other) {
            vector<int> e;
            vector<vector<int>> f;
            for (int i = 0; i < c.size(); i ++)
            {
                for (int j = 0; j < c[i].size(); j ++)
                {
                    e.push_back(c[i][j] - other.c[i][j]);
                }
                f.push_back(e);
                e.clear();
            }
            return Matrix(f);
        }
        Matrix operator*(Matrix& other) {
            vector<int> e;
            vector<vector<int>> f;
            for (int i = 0; i < c.size(); i ++)
            {
                for (int k = 0; k < c.size(); k ++)
                {
                    int sum = 0;
                    for (int j = 0; j < c[i].size(); j ++)
                    {
                        sum += c[i][j] * other.c[j][k];
                    }
                    e.push_back(sum);
                }
                f.push_back(e);
                e.clear();
            }
            return Matrix(f);
        }

        friend ostream& operator<<(ostream& os, const Matrix& matrix) {
            for (int i = 0; i < matrix.c.size(); i ++)
            {
                for (int j = 0; j < matrix.c[i].size(); j ++)
                {
                    os << matrix.c[i][j] << "\t";
                }
                os << endl;
            }
            return os;
        }

    private:
        vector<vector<int>> c;
};

int main()
{
    vector<vector<int>> a = {{1,2,3},{4,5,6}};
    vector<vector<int>> b = {{1,2},{3,4},{5,6}};
    vector<vector<int>> x = {{4,5,6},{4,5,6}};
    
    Matrix A(a);
    Matrix B(b);
    Matrix X(x);

    Matrix sum = A + X;
    Matrix diffrence = X - A;
    Matrix product1 = A * B;
    Matrix product2 = B * A;

    cout << "A + X" << endl;
    cout << sum << endl;
    cout << "X - A" << endl;
    cout << diffrence << endl;
    cout << "A * B" << endl;
    cout << product1 << endl;
    cout << "B * A" << endl;
    cout << product2 << endl;

    return 0;
}