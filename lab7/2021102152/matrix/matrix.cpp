#include<iostream>
#include<vector>
using namespace std;

class Matrix
{
	friend ostream& operator << (ostream &out, Matrix &b);     //����<<�����������Ԫ
public:
 
	Matrix(int a, int b): row(a), column(b){      //���캯������������к��࣬������load��ʼ��
		load();
	};
	
	Matrix operator + (Matrix &b);                      //+��������غ���
    Matrix operator - (Matrix &b);                      //-��������غ���
    Matrix operator * (Matrix &b);                      //*��������غ���
	Matrix &operator = (vector<vector<int>> array);     //=��������غ���
 
private:
 
	void load()                                      //��ʼ�����ݡ����ɶ�Ӧ����Ԫ�ض���0�ľ���
	{
		p = new double*[row];                        //��pָ�� ����doubleָ�������
		for(int i = 0; i<row; i++)
		{
			p[i] = new double[column];               //ÿ��doubleָ����ָ��һ��double����
			for(int t = 0; t<column; t++)            //ѭ����ÿ��Ԫ�ظ�ֵΪ0
				p[i][t] = 0;	
		}
	}
	double **p;                                //��¼�������ݵĵ�ַ
	int row;                                   //��������
	int column;                                //��������
};
//+���������
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
//-���������
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
//*���������
Matrix Matrix::operator *(Matrix &b) 
{
    Matrix temp(this->row, b.column);
    if(temp.column!=b.row)
    {
        cout << "���������" << endl;
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
//=���������
Matrix &Matrix::operator = (vector<vector<int>> array)
{
	for(int i=0; i<row; i++)
		for(int t=0; t<column; t++)
			p[i][t] = array[i][t];
			
	return *this;
}
//<<���������
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
	
	a = arraya;                //��άvector��ֵ������
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

