
#include<iostream>
using namespace std;
class Tru;//声明类Tru
typedef void (Tru::*Refer)();//声明一个指向Tru的类函数Refer()的指针 
Refer fun1;//fun1指针
class Tru
{
    public:
    Tru() //定义一个构造函数
    {
        fun1=&Tru::out_pr1;////使用fun1指针来访问private成员
    }
    void fun2()
    {
        out_pr1();//通过类的public成员函数调用private成员函数
    }
    
    private:
    void out_pr1()
    {
        cout<<"private.out_pr1"<<endl;
    }
    static void out_pr2()
    {
        cout<<"private.out_pr2"<<endl;
    }
    friend void fun3(); //fun3()设为类Tru的友元函数
   
};
void fun3()
{
    Tru::out_pr2();//通过类的友元函数调用该类的private成员函数,该成员函数必须设为static
}


int main()
{
    Tru func;
    (func.*fun1)();
    func.fun2();
    fun3();
    return 0;

}