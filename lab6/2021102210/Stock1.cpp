#include<iostream>
using namespace std;

class Stock
{
private:
void *p(int n)
{
    cout << n ;
}

public:
void *q(int n)
{
    cout << n ;
}
};

int main()
{
    Stock stock ;
    stock.q(5);
    stock.p(5);//编译器显示错误，p指向的函数不可访问
}