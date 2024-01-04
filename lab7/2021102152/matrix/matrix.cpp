#include<iostream>
#include<vector>
using namespace std;

class Matrix
{
	friend ostream& operator << (ostream &out, Matrix &b);     //声明<<运算符重载友元
public:
 
	Matrix(int a, int b): row(a), column(b){      //构造函数，传入矩阵行和类，并调用load初始化
		load();
	};
	
	Matrix operator + (Matrix &b);                      //+运算符重载函数
    Matrix operator - (Matrix &b);                      //-运算符重载函数
    Matrix operator * (Matrix &b);                      //*运算符重载函数
	Matrix &operator = (vector<vector<int>> array);     //=运算符重载函数
 
private:
 
	void load()                                      //初始化数据。生成对应行列元素都是0的矩阵
	{
		p = new double*[row];                        //让p指向 储存double指针的数组
		for(int i = 0; i<row; i++)
		{
			p[i] = new double[column];               //每个double指针再指向一个double数组
			for(int t = 0; t<column; t++)            //循环将每个元素赋值为0
				p[i][t] = 0;	
		}
	}
	double **p;                                //记录矩阵数据的地址
	int row;                                   //矩阵行数
	int column;                                //矩阵列数
};
//+运算符重载
Matrix Matrix::operator +(Matrix &b) 
{
	Matrix temp = *this;
	for(int i=0; i<row; i++)
		for(int t = 0; t<column; t++)
		{
			temp.p[i][t] = this->p[i][t] + b.p[i][t];
		}
	return temp;
}
//-运算符重载
Matrix Matrix::operator -(Matrix &b) 
{
	Matrix temp = *this;
	for(int i=0; i<row; i++)
		for(int t = 0; t<column; t++)
		{
			temp.p[i][t] = this->p[i][t] - b.p[i][t];
		}
	return temp;
}
//*运算符重载
Matrix Matrix::operator *(Matrix &b) 
{
    Matrix temp(this->row, b.column);
    if(temp.column!=b.row)
    {
        cout << "矩阵不能相乘" << endl;
        exit(0);
    }
    else
    {

	int sum = 0;
	for (int i = 0; i < this->row; ++i) 
    {	
		for (int j = 0; j < b.column; ++j) 
        {
			sum = 0;
			for (int k = 0; k < this->column; ++k) 
            {
				sum += this->p[i][k] * b.p[k][j];
			}
			temp.p[i][j] = sum;
		}
    }
        return temp;
    }
}
//=运算符重载
Matrix &Matrix::operator = (vector<vector<int>> array)
{
	for(int i=0; i<row; i++)
		for(int t=0; t<column; t++)
			p[i][t] = array[i][t];
			
	return *this;
}
//<<运算符重载
ostream& operator << (ostream &out, Matrix &b)
{
	for(int i =0; i<b.row; i++)
	{
	 
		for(int t = 0; t<b.column; t++)
		{
			out << b.p[i][t] << " ";
		}
		out << endl; 
	}
	return out; 
	 
}

int main()
{
	vector<vector<int>> arraya = {{1,3,4,3},{5,6,7,5},{8,6,8,7}};
	Matrix a(3, 4);
	
	a = arraya;                //二维vector赋值给矩阵
	cout << a << endl;
	
	vector<vector<int>> arrayb = {{6,3,3,3},{5,2,1,4},{6,6,8,3}};
	Matrix b(3, 4);
 
	b = arrayb;
	cout << b << endl;
	
	b = b + a;
	cout << b << endl;
	 
    b = b - a;
    cout << b << endl;

    b =b * a;
    cout << b << endl;
	return 0;
}

