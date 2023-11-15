#include <iostream>

using namespace std;
//一般类对象 
class C1
{
public:
    int getC1() { return C1data1; } 
    int C1data1;  //4
    int C1data2;  //4
private:
    
    int C1data3;  //4
}; 
//继承类对象 
class C2 : public C1
{
    public:
        int getC2() { return C2data1; } 
        int C2data1; 
    private:
        int C2data2;
        int C2data3; 
}; 
//带虚函数的类对象
class C3
{
    public:
    virtual void func(){}
    virtual void getC3(){}
    int C3data1;
    private:
    int C3data2;
};
//基类有虚函数的子类对象
class C4 : public C3
{
    public:
    virtual void func1(){}
    int C4data1;
    private:
    int C4data2;
};
//基类有虚函数且子类有自己的更多的虚函数的类对象
class C5 : public C3
{
    public:
    virtual void func(){}//覆写基类虚函数func()
    virtual void func1(){}
    virtual void func2(){}
    int C5data1;
    private:
    int C5data2;
};
//多继承的类对象
class C6 : public C1 , public C3
{
    public:
    int C6data1;
    private:
    int C6data2;
};
//虚基类的类对象
class C7 : virtual public C3
{   
    public:
    virtual void func1(){}
    int C7data1;
    private:
    int C7data2;
};
int main()
{
    C1 c1;
    C2 c2;
    C3 c3;
    C4 c4;//子类的虚函数表中，先存放基类的虚函数，在存放子类自己的虚函数。
    C5 c5;//当子类重载了父类的虚函数，则编译器会将子类虚函数表中对应的父类的虚函数替换成子类的函数。
    C6 c6;
    C7 c7;
    //一般类对象：对象地址和首变量地址一致
    cout <<"size c1 ="<< sizeof(c1) << endl;//一个int类型占四个字节，上述代码中一共有三个int类型的成员变量，4*3=12
    cout <<"address c1 ="<< &c1 << endl;
    cout <<"address C1data1 ="<< &c1.C1data1 << endl;
    cout <<"address C1data2 ="<< &c1.C1data2 << endl; 
    //继承类对象：对象地址和基类首变量地址一致，子类变量地址位于基类变量地址后面
    cout <<"size c2 ="<< sizeof(c2) << endl;//子类对象共有六个int类型的成员变量，包含基类对象的三个int类型和自己的三个int类型，4*3+12=24
    cout <<"address c2 ="<< &c2 <<endl;
    cout <<"address C1data1 ="<< &c2.C1data1 <<endl;
    cout <<"address C2data1 ="<< &c2.C2data1 <<endl;
    //带虚函数的类对象：首地址是对象指针指向虚函数表指针vptr
    cout <<"size c3 ="<< sizeof(c3) << endl;
    cout <<"address c3 ="<< &c3 <<endl;
    //对于类的每个对象，编译器都会为其生成一个虚函数表指针，位于该对象内存中的开头，并指向了虚函数表的位置。
	//&c3得到对象c3的首地址，强制转换为(int *)，意为将从&c3开始的4个字节看作一个整体，而&c3就是这个4字节整体的首地址，也就是虚表指针。
    cout <<"address vTable ="<< (int *)(&c3) << endl;
    cout <<"address func() ="<< (int *)*(int *)(&c3) << endl;
    //基类有虚函数的子类对象:子类对象的虚函数表包含基类的虚函数，然后是子类的虚函数
    cout <<"size c4 ="<< sizeof(c4) << endl;
    cout <<"address c4 =" << &c4 <<endl;
    cout <<"address vTable ="<< (int *)(&c4) << endl;
    cout <<"address func() ="<< (int *)*(int *)(&c4) << endl;
    cout <<"address func1() ="<< (int *)*(int *)(&c4)+1 << endl;
    //基类有虚函数且子类有自己的更多的虚函数的类对象：子类对象的虚函数表包含覆写基类的虚函数，然后是子类的虚函数
    cout <<"size c5 ="<< sizeof(c5) << endl;
    cout <<"address c5 ="<< &c5 << endl;
    cout <<"address vTable ="<< (int *)(&c5) << endl;
    cout <<"address func() ="<< (int *)*(int *)(&c5) << endl;
    cout <<"address func1() ="<< (int *)*(int *)(&c5)+1 << endl;
    //多继承的类对象
    cout <<"size c6 ="<< sizeof(c6) << endl;
    cout <<"address c6 ="<< &c6 << endl;
    cout <<"address vTable ="<< (int *)(&c6) << endl;
    cout <<"address C1data1 ="<< &c6.C1data1 << endl;
    cout <<"address C3data1 ="<< &c6.C3data1 << endl;
    cout <<"address C6data1 ="<< &c6.C6data1 << endl;
    cout <<"address func() ="<< (int *)*(int *)(&c6) << endl;
    //虚基类的类对象:虚拟继承的子类的内存结构，和普通继承完全不同。
    //虚拟继承的子类，有单独的虚函数表， 另外也单独保存一份父类的虚函数表，两部分之间用一个四个字节的0x00000000来作为分界。
    //子类的内存中，首先是自己的虚函数表，然后是子类的数据成员，然后是0x0，之后就是父类的虚函数表，之后是父类的数据成员。
    //如果子类没有自己的虚函数，那么子类就不会有虚函数表，但是子类数据和父类数据之间，还是需要0x0来间隔。
    //因此，在虚拟继承中，子类和父类的数据，是完全间隔的，先存放子类自己的虚函数表和数据，中间以0x分界，最后保存父类的虚函数和数据。
    //如果子类重载了父类的虚函数，那么则将子类内存中父类虚函数表的相应函数替换。
    cout <<"size c7 ="<< sizeof(c7) << endl;
    cout <<"address c7 ="<< &c7 << endl;
    cout <<"address vTable ="<< (int *)(&c7) << endl; 
    cout <<"address C3data1 ="<< &c7.C3data1 << endl;
    cout <<"address C7data1 ="<< &c7.C7data1 << endl;
    cout <<"address func1() ="<< (int *)*(int *)(&c7) << endl;
    
}
/*C++类成员中的成员变量和成员函数是分开存储的
同一类中的存储位置也有差别：
普通成员变量：
存储于类的对象当中，与结构体struct变量有相同的内存分布和字节对齐方式
静态成员变量：
存储于全局数据区当中
成员函数：
存储于代码段当中
*/