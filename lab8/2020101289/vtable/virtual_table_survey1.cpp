/*调研虚函数实现的内存结构，包括虚函数表在内存中的位置，
多个不同对象是否指向同一个表等课程里面讲解的内容，并编写程序证明
你调研的结果的正确性。*/

#include <iostream>
using namespace std;

class A
{
    public:
        virtual void fun0() //创建不同虚函数
        {
            cout << "A::fun0" << endl; 
        }
        virtual void fun1() 
        {
            cout << "A::fun1" << endl; 
        }
};

int main()
{
    A a;
    cout << "size of A = " << sizeof(a) << endl;//结果size of A=4
    return 0;
}