#include<iostream>

using namespace std;

class top
{
    public:
    int t;
};

/*class middle1 :   public top
{
    public:
    int m1;
};

class middle2 :   public top
{
    public:
    int m2;
};*///非虚继承的验证

class middle1 : virtual  public top
{
    public:
    int m1;
};

class middle2 : virtual  public top
{
    public:
    int m2;
};//虚继承的验证

class bottom :  public middle1 , public middle2
{
    public:
    int bo;
};

int main()
{
    top topp1;
    middle1 mi1;
    middle2 mi2;
    bottom bot1;
    cout << sizeof(topp1) << endl ;
    cout << sizeof(mi1) << endl ;
    cout << sizeof(mi2) << endl ;
    cout << sizeof(bot1) << endl ;
    cout << &bot1 << endl ;
    cout << &bot1.middle1::t << endl ;
    cout << &bot1.middle2::t << endl ;
    cout << &bot1.m1 << endl ;
    cout << &bot1.m2 << endl ;
    cout << &bot1.bo << endl ;
}