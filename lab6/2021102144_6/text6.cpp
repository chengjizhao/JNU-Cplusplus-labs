#include<iostream>
using namespace std;
//正确做法，使用友元函数，友元函数可以令全局函数访问类的私有变量
class Text6
{
private:
    int a;
    void f_cout();
public:
    friend void f_sure(Text6 t6);
    Text6();
    ~Text6();
};
void Text6::f_cout()
{
    cout<<"yes"<<endl;
}
void f_sure(Text6 t6)
{
   t6.f_cout();
}
Text6::Text6()
{
    a=10;
}

Text6::~Text6()
{
}

int main()
{
   Text6 T6;
   f_sure(T6);
   return 0;
}