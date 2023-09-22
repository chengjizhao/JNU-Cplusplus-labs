#include<iostream>
using namespace std;


int main ()
{
    int b;
    int c=0;
    int d=0;
    int e=0;
    int f[1001]={0};
    f[1]=1;
    for(int a=10;a<1001;a++)
    {
    b=a ;
    for(;b>9;)//对b进行迭代操作
    {
        if(99<b<1001)
        {
            e=b/100;
            d=(b-e*100)/10;
            c=b-e*100-d*10;
            b=e*e+d*d+c*c;
        }
        else
        {
            d=b/10;
            c=b-d*10;
            b=c*c+d*d;
        }
    }
    if(b==1)
    {
        f[a]=1;
    }
    else
    {
        f[a]=0;
    }
    }
    cout << "这是幸福的数" << endl ;
    for(int a=0;a<1001;a++)
    {
        if(f[a]==0)
        {cout << a << "," ;}
    }
    cout << endl ;
    cout << "这是悲伤的数" << endl ;
    for(int a=0;a<1001;a++)
    {
        if(f[a]==1)
        {cout << a << ",";}
    }
    cout << endl ;
    return 0;
}