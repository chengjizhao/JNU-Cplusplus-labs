#include<iostream>
using namespace std;

class shape
{
    public:
    double get_area()
    {
        cout<<"计算面积"<<endl;
    }
    double get_girth()
    {
        cout<<"计算周长"<<endl;
    }
};

class circle:public shape
{
    private:
    double radius;

    public:
    double set_radius(double r)
    {
        radius=r;
        cout<<"圆的半径："<<radius<<endl;
    }
    double get_area()
    {
        cout<<"圆的面积："<<3.14*radius*radius<<endl;
    }
    double get_girth()
    {
        cout<<"圆的周长："<<2*3.14*radius<<endl;
    }
};
class rectangle:public shape
{
    private:
    double length;
    double width;

    public:
    double set(double l,double w)
    {
        length=l;
        width=w;
        cout<<"矩形的长："<<length<<endl;
        cout<<"矩形的宽："<<width<<endl;
    }
    double get_area()
    {
        cout<<"矩形的面积"<<length*width<<endl;
    }
    double get_girth()
    {
        cout<<"矩形的周长"<<2*(length+width)<<endl;
    }
};

int main()
{
    circle a;
    a.set_radius(2.0);
    a.get_area();
    a.get_girth();
    rectangle b;
    b.set(3.0,4.0);
    b.get_area();
    b.get_girth();

    return 0;
}