#include<iostream>
#include<vector>
using namespace std;

class matrix
{
private:
    int M[50][50];
public:
    int n;
    matrix(int a,bool x){
        n=a;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                M[i][j]=0;
            }
        }
    }
    matrix(int a){
        n=a;
        int x;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>x;
                M[i][j]=x;
            }
        }
    }
    friend matrix operator+(const matrix &a,const matrix &b);
    friend matrix operator-(const matrix &a,const matrix &b);
    friend matrix operator*(const matrix &a,const matrix &b);
    friend void operator<<(ostream &os,const matrix &m);
};

