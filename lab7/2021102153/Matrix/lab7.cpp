#include"lab7.h"
Matrix::Matrix(int a,int b)//构造一个a*b的二维vector
    {
        r=a;
        c=b;
    vec.resize(a); //这里创建一个a*b的二维vector
    for(int i = 0;i<a;i++)
    {
  
        vec[i].resize(b);  
    }
       for (int i=0; i<a; i++) {
        for (int j=0; j<b; j++) {
            vec[i][j]=i*10+j;//初始化值
        }
    }
    }

Matrix Matrix::operator+ (const Matrix& m)
    {   
        Matrix t(r,c);
        if(r!=m.r||c!=m.c)
        {
        cout << "false" <<endl;
        }
            else{

            cout << "true" << endl;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {   
                    t.vec[i][j]=vec[i][j]+m.vec[i][j];
                }
            }
            
    }
    return t;
    }

Matrix Matrix::operator-(const Matrix &m)
{   
    Matrix t(r,c);
    if(r!=m.r||c!=m.c)
    {
        cout << "false" <<endl;

    }
    else{
        cout << "true" << endl;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                    t.vec[i][j]=vec[i][j]-m.vec[i][j];
            }
        }
            
    }
    return t;
}

Matrix Matrix::operator*(const Matrix &m)
{        Matrix t(r,m.c);
    if(c!=m.r)
    {
        cout<<"false"<<endl;
    }
    else{
        for(int i=0;i<r;i++)
        {
            for(int j=0; j<m.c;j++)
            {
                t.vec[i][j]=0;
            }
        }
        for(int i=0;i<t.r;i++)
        {
            for(int j=0;j<t.c;j++)
            {
                for(int k=0;k<c;k++)
                {
                    t.vec[i][j]+=(vec[i][k]*m.vec[k][j]);
                }
            }
        }
     
    }
    return t;
}

ostream& operator<<(ostream& out,Matrix &p)
{   
    for(int i=0;i<p.r;i++)
        {   out << endl;
            for(int j=0;j<p.c;j++)
            {
                out << p.vec[i][j] <<" ";
            }
        }
        return out;
}



int main()
{
    Matrix a(2,3);
    Matrix b(2,3);
    Matrix c(3,2);
    cout<<a<<endl;
    a=a+b;
    cout<< a <<endl;
    a=a-b;
    cout<< a <<endl;
    a=a*c;
    cout<< c <<endl;
    cout<< a <<endl;

}