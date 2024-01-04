#include <iostream>
using namespace std;
class Base
{
public:
    virtual void func1() { cout << "Base::func1()" << endl; }
    virtual void func2() { cout << "Base::func2()" << endl; }
};

int main()
{
    Base b;
    typedef void (*Fun)(void);
    Fun pFun = NULL;

    // 取出虚指针
    Fun *pVtab = (Fun *)*(int *)(&b);

    // 通过虚指针访问虚函数表中的内容
    pFun = pVtab[0];
    pFun();

    pFun = pVtab[1];
    pFun();

    return 0;
}
