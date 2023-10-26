/*用vector容器，实现一个新的类Matrix， 重载运算符 “+，-，*”，实现矩阵的加减乘，
并实现cout 直接输出矩阵。*/

#include <iostream>
#include<vector>
using namespace std;

class matrix 
{
    public:
	int r, c;
	int** mem;//m里面存放的是当前指向整型变量的地址的地址，*m表示的是指向整型变量的地址,**m就指的是整型变量
	matrix(int a, int b)
    {
		r = a;//矩阵的行
		c = b;//列
		mem = new int* [a];
		for (int i = 0; i < a; i++) 
        {
			mem[i] = new int[b];
		}
	};
	matrix(const matrix& p) //改写拷贝构造函数
    {
		r = p.r;
		c = p.c;
		mem = new int* [r];
		for (int i = 0; i < r; i++) 
        {
			mem[i] = new int[c];
		}
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) 
            {
				mem[i][j] = p.mem[i][j];
			}
	}
	~matrix() //析构函数释放动态分配的内存
    {
		for (int i = 0; i < r; i++) 
        {
			delete[]mem[i];
		}
		delete[]mem;
	};
	matrix operator+ (const matrix& m)//矩阵加法 
    {
		if (r != m.r || c != m.c) //判断两个矩阵的行宽或列宽是否一致
        {
			cout << "error";
			matrix tmp(r, c);
			tmp.mem = NULL;
			return tmp;
		}
		else 
        {
			matrix tmp(r, c);
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					tmp.mem[i][j] = mem[i][j] + m.mem[i][j];//逐个相加
			return tmp;
		}
	}
	matrix operator- (const matrix& m) //矩阵减法
    {
		if (r != m.r || c != m.c) 
        {
			cout << "error";
			matrix tmp(r, c);
			tmp.mem = NULL;
			return tmp;
		}
		else 
        {
			matrix tmp(r, c);
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					tmp.mem[i][j] = mem[i][j] - m.mem[i][j];
			return tmp;
		}
	}
	matrix operator* (const matrix& m)//矩阵乘法
	{
		if (c != m.r) //判断行数是否等于另一个矩阵的列数
        {
			cout << "error";//不相等则不能进行乘法
			matrix tmp(r, c);
			tmp.mem = NULL;
			return tmp;
		}
		else 
        {
			matrix tmp(r, m.c);
			for (int i = 0; i < r; i++)
				for (int j = 0; j < m.c; j++)
					tmp.mem[i][j] = 0;
			for (int i = 0; i < tmp.r; i++)
				for (int j = 0; j < tmp.c; j++)
					for (int k = 0; k < c; k++)
						tmp.mem[i][j] += (mem[i][k] * m.mem[k][j]);
			return tmp;
		}
	}
	
	matrix & operator=(const matrix& m)//“=”运算符重载
	{
		if (c != m.r) 
        {
			cout << "error";
			matrix tmp(r, c);
			tmp.mem = NULL;
			return tmp;
		}
		else 
        {
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					mem[i][j] = m.mem[i][j];
			return *this;
		}
	}
	friend void display(matrix m)//输出矩阵
	{
		for (int i = 0; i < m.r; i++) {
			for (int j = 0; j < m.c; j++) {
				cout << m.mem[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "====================================================================================" << endl;
	}
};

int main()//实现举例
{
    matrix p1(1,2),p2(1,2),p3(2,1);
    int num1=0,num2=1,num3=2;
    for(int i=0;i<p1.r;i++)
       for(int j=0;j<p1.c;j++)
       {
          p1.mem[i][j]=num1;
          num1++;
       } 
    for (int i = 0; i < p2.r; i++)
		for (int j = 0; j < p2.c; j++) 
        {
			p2.mem[i][j] = num2;
			num2++;
		}
	for (int i = 0; i < p3.r; i++)
		for (int j = 0; j < p3.c; j++) 
        {
			p3.mem[i][j] = num3;
			num3++;
		}
	matrix p11 = p1 + p2;
	cout << "p1" << endl;
	display(p1);
	cout << "p2" << endl;
	display(p2);
	cout << "p3" << endl;
	display(p3);
	cout << "p11" << endl;
	display(p11);
	cout << "p1+p2" << endl;
	display(p1 + p2);
	system("pause");
}
