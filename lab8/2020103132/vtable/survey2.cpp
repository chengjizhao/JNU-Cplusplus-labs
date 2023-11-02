/*调研虚函数实现的内存结构，包括虚函数表在内存中的位置，
多个不同对象是否指向同一个表等课程里面讲解的内容，并编写程序证明
你调研的结果的正确性。*/


#include <iostream>
using namespace std;

class A
{
    public:
        virtual void fun0() 
        { 
            cout << "A::fun0" << endl;
        }
};

class B
{
    public:
        virtual void fun0() 
        { 
            cout << "B::fun0" << endl; 
        }
};

class C
{
    public:
        virtual void fun0() 
        { 
            cout << "C::fun0" << endl; 
        }
};

class D : public A, public B, public C {};

int main()
{
    D d;
    cout << "size of D = " << sizeof(d) << endl;//结果为12
    return 0;
}