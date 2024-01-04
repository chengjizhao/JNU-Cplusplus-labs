#include "matrix.h"
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"请输入矩阵大小n:";
    cin>>n;
    cout<<endl<<"请输入矩阵A:"<<endl;
    matrix a(n);
    cout<<endl<<"请输入矩阵B:"<<endl;
    matrix b(n);
    matrix result(n,1);

    result=a+b;
    cout<<endl<<"a+b结果为:"<<endl;
    cout<<result;
    result=a-b;
    cout<<endl<<"a-b结果为:"<<endl;
    cout<<result;
    result=a*b;
    cout<<endl<<"a*b结果为:"<<endl;
    cout<<result;
    return 0;
}