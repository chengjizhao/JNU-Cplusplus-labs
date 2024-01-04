#include <iostream>
#include <vector>
using namespace std;

class Martix
{
private:
	int _row, int _col;
public:
	vector<vector<double>>mat;
	Martix(int row, int col) :_row(row), _col(col)
	{
		mat.resize(row, vector<double>(col, 0));
	}
	Martix operator+(const Martix & other)//实现加法重载
	{
		Martix add(_row, _col);
		for (int q = 0; q < _row; ++q)
		{
			for (int y = 0; y < _col; ++y)
			{
				add.mat[q][y] = mat[q][y] + other.mat[q][y];
			}
		}
		return add;
	}
	Martix operator-(const Martix& other)//实现减法重载
	{
		Martix minus(_row, _col);
		for (int q = 0; q < _row; ++q)
		{
			for (int y = 0; y < _col; ++y)
			{
				minus.mat[q][y] = mat[q][y] - other.mat[q][y];
			}
		}
		return minus;
	}
	Martix operator*(const Martix& other)//实现乘法重载
	{
		Martix mult(_row, _col);
		for (int q = 0; q < _row; ++q)
		{
			for (int y = 0; y < _col; ++y)
			{
				mult.mat[q][y] = mat[q][y] - other.mat[q][y];
			}
		}
		return mult;
	friend ostream& operator<<(ostream & os, const Matrix & matrix) 
	{
			for (int i = 0; i < matrix._row; ++i) 
			{
				for (int j = 0; j < matrix._col; ++j) 
				{
					os << matrix.m_data[i][j] << " ";
				}
				os <<endl;
			}
			return os;
		}
	}
};

int main()
{
	Martix a = (3,3);
	a = { {1,2,3},{4,5,6},{7,8,9} };
	Martix b = (3,3);
	b = { {7,8,9},{4,5,6},{1,2,3} };
	Martix c = a + b;
	Martix d = a - b;
	Martix e = a * b;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	return 0;
}