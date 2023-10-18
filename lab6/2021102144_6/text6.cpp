#include<iostream>
using namespace std;
//正确做法，使用友元函数，友元函数可以令全局函数访问类的私有变量
class Text6
{
private:
    int a;
public:
friend void f_cout(Text6 t6);
    Text6();
    ~Text6();
};
void f_cout(Text6 t6)
{
    cout<<t6.a<<endl;
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
   f_cout(T6);
   return 0;
}