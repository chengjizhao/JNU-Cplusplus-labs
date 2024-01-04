#include "matrix.h"
#include<iostream>
using namespace std;

void operator<<(ostream &os,const matrix &m){
    for(int i=0;i<m.n;i++){
        for(int j=0;j<m.n;j++){
            os<<m.M[i][j]<<" ";
        }
        os<<endl;
    }
}

matrix operator+(const matrix &a,const matrix &b){
    matrix ans(a.n,1);
    for(int i=0;i<a.n;i++){
        for(int j=0;j<a.n;j++){
            ans.M[i][j]=a.M[i][j]+b.M[i][j];
        }
    }
    return ans;
}

matrix operator-(const matrix &a,const matrix &b){
    matrix ans(a.n,1);
    for(int i=0;i<a.n;i++){
        for(int j=0;j<a.n;j++){
            ans.M[i][j]=a.M[i][j]-b.M[i][j];
        }
    }
    return ans;
}

matrix operator*(const matrix &a,const matrix &b){
    matrix ans(a.n,1);
    for(int i=0;i<a.n;i++){
        for(int j=0;j<a.n;j++){
            for(int k=0;k<a.n;k++){
                ans.M[i][j]+=(a.M[k][j]*b.M[i][k]);
            }
        }
    }
    return ans;
}