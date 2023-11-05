/*调研虚函数实现的内存结构，包括虚函数表在内存中的位置，
多个不同对象是否指向同一个表等课程里面讲解的内容，并编写程序证明
你调研的结果的正确性。*/

//虚函数表在内存中的位置
#include <iostream>
#include <stdio.h>
using namespace std;

class A
{
    public:
    int x;
    virtual void b() {}
};

int main()
{
    A* p = new A;
    cout << p << endl;
    cout << &p->x << endl;/*相差4字节，因此编译器把生成的虚函数表放在了最前面*/
    return 0;
}