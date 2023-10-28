#include<iostream>
#include<vector>
using namespace std;
class Matrix
{
    public:
    Matrix()
    {}
    Matrix operator+(const Matrix&other)const
    {
        Matrix sum;
        int r=Creat.size();//二维数组中这里是指里面包含的vector数量，即行数
        int c=Creat[0].size();//这里是指第一个vector包含的int类型的数量，即列数
        vector<vector<int>>Cr(r,vector<int>(c,0));//由于vector不写入东西是无法用下标访问的，故写入r行c列个0。
        sum.Creat=Cr;//拷贝
        for(int i=0;i<r;i++)
        {
           for(int j=0;j<c;j++)
           {
            sum.Creat[i][j]=Creat[i][j]+other.Creat[i][j];
           }
        }
        return sum; 
    }   
    Matrix operator-(const Matrix&other)const
    {
        Matrix sum;
        int r=Creat.size();
        int c=Creat[0].size();
        vector<vector<int>>Cr(r,vector<int>(c,0));
        sum.Creat=Cr;
        for(int i=0;i<r;i++)
        {
           for(int j=0;j<c;j++)
           {
            sum.Creat[i][j]=Creat[i][j]-other.Creat[i][j];
           }
        }
        return sum; 
    }
    Matrix operator*(const Matrix&other)const
    {
        Matrix sum,null;
        int r=Creat.size();
        int c=other.Creat[0].size();
        if(r!=c)
        {
            cout<<"错误，两矩阵相乘前行数等于后列数才有意义"<<endl;
            return null;
        }
        vector<vector<int>>Cr(r,vector<int>(c,0));
        sum.Creat=Cr;
        for(int m=0;m<r;m++)
        {
            for(int n=0;n<c;n++)
            {
                int Sum=0;
                for(int i=0;i<r;i++)
                {
                Sum+=(Creat[m][i]*other.Creat[i][n]);         
                }
                sum.Creat[m][n]=Sum;
            }
        }
        return sum; 
    }
    void show()
    {
    for(int i=0;i<Creat.size();i++)
    {
     for(int j=0;j<Creat[0].size();j++)
     cout<<Creat[i][j]<<" ";
     cout<<endl;
    }
    cout<<endl;
    }
    vector<vector<int>>Creat;
    private:
};
int main()
{
    Matrix m1,m2,m3,m;
    m1.Creat={{1,2,3},{3,2,5},{3,2,1}};
    m2.Creat={{2,2,4},{3,2,5},{2,3,4}};
    m3.Creat={{2,3},{3,4}};
    m=m1+m2;
    m.show();
    m=m1-m2;
    m.show();
    m=m1*m2;
    m.show();
    m=m1*m3;
    m.show();
    return 0;
}