#include<iostream>
#include<cmath>
using namespace std;
class Shape
{
    public:
    double long_line;
    double short_line;
    double radius;
    protected:
    double pi=3.1415926;
};
class Circle:public Shape
{
    public:
    void Area()
    {
       cout<<pow(radius,2)*pi<<endl;
    }
    void Long()
    {
        cout<<2*pi*radius<<endl;
    }
};
class Rectangle:public Shape
{
    public:
    void Area()
    {
       cout<<long_line*short_line<<endl;
    }
    void Long()
    {
       cout<<2*long_line+2*short_line<<endl;
    }
};
int main()
{
    Circle c;
    Rectangle r;
    int num;
    while(num!=5)
    {
    cout<<"您好，欢迎来到计算系统："<<endl
    <<"1、计算圆形面积  2、计算圆形周长"<<endl
    <<"3、计算长方形面积  4、计算长方形周长"<<endl
    <<"5、退出系统"<<endl;
    cin>>num;
    switch (num)
    {
    case 1:
        cout<<"请输入半径"<<endl;
        cin>>c.radius;
        c.Area();
        break;
         case 2:
        cout<<"请输入半径"<<endl;
        cin>>c.radius;
        c.Long();
        break;
         case 3:
        cout<<"请输入长边"<<endl;
        cin>>r.long_line;
        cout<<"请输入短边"<<endl;
        cin>>r.short_line;
        r.Area();
        break;
         case 4:
          cout<<"请输入长边"<<endl;
        cin>>r.long_line;
        cout<<"请输入短边"<<endl;
        cin>>r.short_line;
        r.Long();
        break;
    default:
        break;
    }
    }
    return 0;
}