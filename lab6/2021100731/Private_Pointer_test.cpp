#include <iostream>

using namespace std;

class test_class
{
private:
    int private_var;
    void private_func()
    {cout << "good" << endl;}
public:
    int public_func2(int n);
    int public_func();
    int get_privatevar();
    static auto return_privateptr()
    {
        return &test_class::private_func;
    }
    test_class(){private_var = 1;}
};


//当成功使用私有函数时，会打印good
int main()
{
    test_class Dummy;
    void (test_class::*funptr)() = test_class::return_privateptr();
    
    (Dummy.*funptr)();
    return 0;
}
//此种方法虽然成功使用指针使用了私有函数，但是仍然需要一个公共函数返回私有函数的指针。
//https://blog.csdn.net/ithiker/article/details/113880230
//这篇文章给出了一种通过显示模板特化、友员函数声明的方法来调用私有函数。大部分还没看懂。