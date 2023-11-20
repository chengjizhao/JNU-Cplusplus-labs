/*就差不知道怎么用虚函数指针调用虚函数去证明，其他的证明了也打印出来了*/

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
    // 普通类
    cout << "普通类 Base1内存结构：" << endl;
    cout << "Base1对象b1的起始地址：" << &b1 << endl;
    cout << "b1成员m_base11地址：" << &b1.m_base11 << endl;
    cout << "b1成员m_base12地址：" << &b1.m_base12 << endl;
    cout << "将第一个int成员的地址加1也可以得到第二个成员地址：" << (int *)&b1.m_base11 + 1 << endl;
    cout << "从而验证了成员在内存里的顺序" << endl;
    cout << "虚函数表的起始地址:" << (void *)*(long long *)&b1 << endl; // 偏移一个指针宽度
    cout << "由于Base1没有虚函数，没有虚函数表，虚函数表地址为NUll；" << endl;
    cout << endl;
    // 有虚函数的类
    cout << "有虚函数的类 Base2内存结构：" << endl;
    cout << "vfptr地址：" << &b2 << endl;
    cout << "虚函数表指针（虚函数表地址）:" << (void *)*(intptr_t *)&b2 << endl;
    auto vfptr = *(long long *)&b2;      // 虚函数表地址
    auto ppfunc1 = (long long *)vfptr;   // 第一个虚函数指针的地址
    FUNC func1 = (FUNC)*ppfunc1;         // 从第一个虚函数指针地址取出第一个虚函数指针，然后转成我们要的函数指针类型就可以用来调用
    FUNC func2 = (FUNC) * (ppfunc1 + 1); // 从第二个虚函数指针地址取出第二个虚函数指针
    func1();
    func2();
    cout << "验证了虚函数表里虚函数指针的排列顺序" << endl;
    cout << endl;
    // 继承了有虚函数的类，并改写了第二个虚函数，增加了一个虚函数。
    cout << "继承了有虚函数的类，并改写了第二个虚函数，增加了一个虚函数 D内存结构：" << endl;
    cout << "vfptr地址：" << &d << endl;
    cout << "虚函数表指针:" << (void *)*(long long *)&d << endl;
    vfptr = *(long long *)&d; // 虚函数表地址
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
    // 多继承的类：
    cout << "多继承的类 M内存结构:" << endl;
    cout << "vfptr地址：" << &m << endl;
    // cout << "第一个虚函数表指针:" << (void *)*(long long *)&m << endl;
    Base2 *pbase2 = &m;
    vfptr = *(long long *)pbase2;
    cout << "第一个虚函数表指针:" << (long long *)vfptr << endl;
    // cout << "第一个虚函数表指针:" << vfptr << endl;//探究与上面的写法不同在哪
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
    // 有虚基类的类
    cout << "有虚基类的类 vD内存:" << endl;
    cout << &vd.m_vd << endl;
    cout << &vd.m_base11 << endl;
    cout << &vd.m_base12 << endl;
    cout << "从以上地址可以看出内存结构" << endl;
    return 0;
}

//  1.&a代表对象b的起始地址
//  2.(intptr_t*)&a 强转成intptr_t*类型,为了后面取b对象的一个指针宽度的字节,这是虚表指针
//  3.*(intptr_t*)&a 取一个指针宽度的字节,即vptr虚表地址
//   cout << "A__vfptr地址：" << &a << endl;                            // 带有虚函数的虚函数表指针的地址为类对象的起始地址
//   cout << "A虚函数表的起始地址:" << (void *)*(intptr_t *)&a << endl; // 偏移一个指针宽度
//  根据上面的解析我们知道*(intptr_t*)&b是vptr,即虚表指针.并且虚表是存放虚函数指针的
//  所以虚表中每个元素(虚函数指针)为(intptr_t *)*(intptr_t *)&a
//  这样强转后为了后面的一个指针宽度.所以*(intptr_t*)*(intptr_t*)&a就是虚表的第一个元素.即fun1()的地址.
//  那么接下来的取第二个虚函数地址也就依次类推.  始终记着vptr指向的是一块内存,
//  这块内存存放着虚函数地址,这块内存就是我们所说的虚表.
//   cout << "虚函数表第一个虚函数指针的地址:" << (void *)*(intptr_t *)*(intptr_t *)&a << endl;       // 再次偏移一个指针宽度得到虚函数表中第一个虚函数的地址
//   cout << "虚函数表第二个虚函数指针的地址:" << (void *)*((intptr_t *)*(intptr_t *)&a + 1) << endl; // 通过虚函数表中第一个虚函数的地址的偏移量+1得到第二个虚函数的地址
