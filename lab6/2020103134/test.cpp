#include<iostream>
using namespace std;
class test
{
    private:
    void method();
    static void method1();
    

    public:
    test()
    {
        int (test::*p_)()=&test::method();//test类的成员函数指针
    }
    void call_method();
    void call_private();
    friend void call_private1();

};

void test::method()
{
    cout<<"2023"<<endl;
}

void test::method1()
{
    cout<<"2024"<<endl;
}
//试图通过函数指针的方式规避“只有类的内部函数才能调用私有成员函数”规则
void test::call_method()
{
    return (test.*p_);
}

// 调用私有函数的正确做法1是在公有函数中调用私有函数
void test::call_private()
{
    method();
}
//做法2是通过类的友元函数调用私有函数，但是私有函数必须是设为了static
void call_private1()
{
    test::method1;
}

int main()
{
    test test1;
    tes1.call_method();
    test1.call_private();
    test1.call_private1();
    return 0;
}