#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> martix_add(3);
vector<vector<int>> martix_x(3);
vector<vector<int>> martix_sub(3);
void check(vector<vector<int>> &M); // 遍历全局函数声明
void test_size();

class Martix
{
    friend void check(vector<vector<int>> &M); // 友元
public:
    vector<vector<int>> martix;

    void operator+(Martix &m) const
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int sum;
                sum = martix[i][j] + m.martix[i][j];
                martix_add[i].push_back(sum);
            }
        }
    }
    void operator-(Martix &m) const
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int sum;
                sum = martix[i][j] - m.martix[i][j];
                martix_sub[i].push_back(sum);
            }
        }
    }
    void operator*(Martix &m) const
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int date;
                date = martix[i][j] * m.martix[0][j] + martix[i][j] * m.martix[1][j] + martix[i][j] * m.martix[2][j];
                martix_x[i].push_back(date);
            }
        }
    }
};
int main()
{
    Martix A;
    Martix B;
    // 直接定义写法
    A.martix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    check(A.martix);
    B.martix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    check(B.martix);
    A + B;
    check(martix_add);
    A - B;
    check(martix_sub);
    A *B;
    check(martix_x);
    // test_size();//测试字节用

    /*   // 动态分配写法
        vector<vector<int>> m;
        vector<int> v;
        for (int i = 0; i < 3; i++)
        {
            for (int i = 0; i < 3; i++)
            {
                int value;
                cin >> value;
                v.push_back(value);
            }
            m.push_back(v);
            v.clear();
        }

        check(m);*/
}

void check(vector<vector<int>> &M)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void test_size()
{
    Martix C;
    C.martix = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    cout << sizeof(C.martix) << endl;
}