#include<iostream>
#include<vector>

using namespace std;
class matrix
{
    private:
    int rows;
    int cols;
    vector<vector<int> > data;

    public:
    matrix(vector<vector<int> > & m);
    matrix operator+(matrix & m);
    matrix operator-(matrix & m);
    matrix operator*(matrix & m);
    friend ostream& operater<<(ostream &os,matrix & m);
};

matrix::matrix(vector<vector<int>> & m)
{
    this->data=m;
    rows=m.size();
    cols=m[0].size();
}

matrix matrix::operator+(matrix &m)
{
    vector<vector<int> > sum;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            sum[i][j]=data[i][j]+m.data[i][j];
        }
    }
    return matrix(sum);
}

matrix matrix::operator-(matrix &m)
{
    vector<vector<int> > diff;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            diff[i][j]=data[i][j]-m.data[i][j];
        }
    }
    return matrix(diff);
}

matrix matrix::operator*(matrix &m)
{
    vector<vector<int> > mul;
    vector<int> sum;
    for(int i=0;i<rows;i++)
    {
        for(int p=0;p<m.rows;p++)
        {
            int sum_=0;
            for(int j=0;j<cols;j++)
            {
                sum_+=data[i][j]+m.data[j][p];
            }
            sum.push_back(sum_);
        }
        mul.push_back(sum);
        sum={0};
    }
    return matrix(mul);
}

ostream& operater<<(ostream &os,matrix & m);
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
    return os;
}

int main()
{
    vector<vector<int> > a={{1,1},{2,2}};
    vector<vector<int> > b={{3,3},{4,4}};
    matrix m_a(a);
    matrix m_b(b);
    matrix m_c=m_a+m_b;
    cout<<m_c;
    matrix m_d=m_a-m_b;
    cout<<m_d;
    matrix m_e=m_a*m_b;
    cout<<m_e;
    return 0;
}