#include <iostream>
using namespace std;
typedef void (*FUNC)();

class Base1 // 普通类
{
public:
    void base1() { cout << "Base1::base1()" << endl; }
    int m_base11;
    int m_base12;
};

class Base2 // 带有虚函数的类
{
public:
    virtual void base21() { cout << "Base2::base21()" << endl; }
    virtual void base22() { cout << "Base2::base22()" << endl; }
    int m_base21;
    int m_base22;
};
class Base3 // 带有虚函数的类
{
public:
    virtual void base31() { cout << "Base3::base31()" << endl; }
    virtual void base32() { cout << "Base3::base32()" << endl; }
    int m_base31;
    int m_base32;
};

class D : public Base2 // 继承类,重写了一个基类虚函数，新增了自己的虚函数
{
public:
    virtual void base22() { cout << "D::base22()" << endl; }
    virtual void d() { cout << "D::d()" << endl; }
    int m_D1;
};

class vD : virtual public Base1
{
public:
    int m_vd;
};

class M : public Base2, public Base3
{
};

int main()
{
    Base1 b1;
    Base2 b2;
    D d;
    vD vd;
    M m;
    cout << "普通类 Base1内存结构：" << endl;
    cout << "Base1对象b1的起始地址：" << &b1 << endl;
    cout << "b1成员m_base11地址：" << &b1.m_base11 << endl;
    cout << "b1成员m_base12地址：" << &b1.m_base12 << endl;
    cout << "将第一个int成员的地址加1也可以得到第二个成员地址：" << (int *)&b1.m_base11 + 1 << endl;
    cout << "从而验证了成员在内存里的顺序" << endl;
    cout << "虚函数表的起始地址:" << (void *)*(long long *)&b1 << endl;
    cout << "由于Base1没有虚函数，没有虚函数表，虚函数表地址为NUll；" << endl;
    cout << endl;
    cout << "有虚函数的类 Base2内存结构：" << endl;
    cout << "vfptr地址：" << &b2 << endl;
    cout << "虚函数表指针（虚函数表地址）:" << (void *)*(intptr_t *)&b2 << endl;
    auto vfptr = *(long long *)&b2;  
    auto ppfunc1 = (long long *)vfptr;   
    FUNC func1 = (FUNC)*ppfunc1; 
    FUNC func2 = (FUNC) * (ppfunc1 + 1); 
    func1();
    func2();
    cout << "验证了虚函数表里虚函数指针的排列顺序" << endl;
    cout << endl;
    cout << "继承了有虚函数的类，并改写了第二个虚函数，增加了一个虚函数 D内存结构：" << endl;
    cout << "vfptr地址：" << &d << endl;
    cout << "虚函数表指针:" << (void *)*(long long *)&d << endl;
    vfptr = *(long long *)&d;
    ppfunc1 = (long long *)vfptr;
    func1 = (FUNC)*ppfunc1;
    func2 = (FUNC) * (ppfunc1 + 1);
    FUNC func3 = (FUNC) * (ppfunc1 + 2);
    func1();
    func2();
    func3();
    cout << "验证了继承了带虚函数的类后，虚函数表里虚函数指针的排列顺序" << endl;
    cout << "d成员m_D1地址：" << &d.m_D1 << endl;
    cout << "d从Base2继承的成员m_base21的地址加2也是m_D1的地址：" << (int *)&d.m_base21 + 2 << endl;
    cout << "从而验证了成员在内存里的顺序" << endl;
    cout << endl;
    cout << "多继承的类 M内存结构:" << endl;
    cout << "vfptr地址：" << &m << endl;
    Base2 *pbase2 = &m;
    vfptr = *(long long *)pbase2;
    cout << "第一个虚函数表指针:" << (long long *)vfptr << endl;
    ppfunc1 = (long long *)vfptr;
    func1 = (FUNC)*ppfunc1;
    func2 = (FUNC) * (ppfunc1 + 1);
    func1();
    func2();
    Base3 *pbase3 = &m;
    vfptr = *(long long *)pbase3;
    cout << "第二个虚函数表指针:" << (long long *)vfptr << endl;
    cout << "从第一、二个虚表地址可以看出内存顺序，验证结果正确" << endl;
    ppfunc1 = (long long *)vfptr;
    func1 = (FUNC)*ppfunc1;
    func2 = (FUNC) * (ppfunc1 + 1);
    func1();
    func2();
    cout << "调用正确 验证成功" << endl;
    cout << endl;
    cout << "有虚基类的类 vD内存:" << endl;
    cout << &vd.m_vd << endl;
    cout << &vd.m_base11 << endl;
    cout << &vd.m_base12 << endl;
    cout << "从以上地址可以看出内存结构" << endl;
    return 0;
}