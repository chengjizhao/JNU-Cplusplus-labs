#include<iostream>
#include<vector>
using namespace std;

class Matrix
{
    private:
    vector<vector<int>> V;
    public:
    Matrix(vector<vector<int>> &other)
    {
        V=other;
    }
    
    
    Matrix operator +(const Matrix &other) const//对加法运算符的重载
    {
        vector<vector<int>> Nvector=other.V;
        if(other.V.size()==V.size())
        {
            for(int i=0;i<other.V.size();i++)
            {
                if(V[i].size()==other.V[i].size())
                {
                    for(int j=0;j<V[i].size();j++)
                    {
                        Nvector[i][j]=(V[i][j]+other.V[i][j]);
                    }
                }
                else 
                {
                    cout << "false" ;
                }
            }
        }
        else
        {
            cout << "false" << endl;
        }
        return Matrix(Nvector);
    }


    Matrix operator -(const Matrix &other) const//对减法运算符的重载
    {
        vector<vector<int>> Nvector=other.V;
        if(other.V.size()==V.size())
        {
            for(int i=0;i<other.V.size();i++)
            {
                if(V[i].size()==other.V[i].size())
                {
                    for(int j=0;j<V[i].size();j++)
                    {
                        Nvector[i][j]=(V[i][j]-other.V[i][j]);
                    }
                }
                else 
                {
                    cout << "false" ;
                }
            }
        }
        else
        {
            cout << "false" << endl;
        }
        return Matrix(Nvector);
    }

    Matrix operator *(const Matrix &other) const 
    {
        vector<vector<int>> Nvector={{0},{0}};
        for(int i=2;i<V.size();i++)
        {
            Nvector.push_back({0});
        }
        for(int i=0;i<Nvector.size();i++)
        {
            for(int j=1;j<other.V[0].size();j++)
            {
                Nvector[i].push_back(0);
            }
        }
        if(other.V[0].size()==V.size())
        {
            for(int i=0;i<Nvector.size();i++)
            {
                for(int j=0;j<Nvector[0].size();j++)
                {
                    for(int a=0;a<V.size();a++)
                    {
                        Nvector[i][j]=Nvector[i][j]+V[i][a]*other.V[a][j];
                    }
                }
            }
        }
        else
        {
            cout << false ;
        }
        return Nvector;
    }

    friend ostream & operator <<(ostream & os,const Matrix & other)//重载"<<"运算符，使其能输出Matrix类型
    {
        for(int i=0;i<other.V.size();i++)
        {
            for(int j=0;j<other.V[i].size();j++)
            {
                os << other.V[i][j] << " ";
            }
            cout << endl ;
        }
        return os;
    }
};


int main()
{
    vector<vector<int>> V={{2,5,5},{6,8,9},{2,6,9}};
    vector<vector<int>> C={{1,4,6},{3,2,5},{2,1,9}};
    Matrix matrix1(V);
    Matrix matrix2(C);
    Matrix matrix3=matrix2*matrix1;
    cout << matrix3;
}