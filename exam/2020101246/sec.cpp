//请解释C++中虚函数表的概念以及编译器如何为每个包含虚函数的类生成该表的。
//为了证明虚函数表的存在，你会如何修改一个类并通过实例访问虚函数表中的内容？
//说明在继承中虚函数表是如何工作的，派生类是如何与基类共享虚函数表的。并用UML图画出一种设计模式，它使用了虚函数来达成目标。

#include<iostream>
using namespace std;
class Father
{
    public:
    virtual void display1(){cout<<"This is Father fir"<<endl;}
    virtual void display2(){cout<<"This is Father fir"<<endl;}
};

class Son:public Father
{
    public:
    void display1  () override{cout<<"This is Son"<<endl;}
    void display2  () override{cout<<"This is Son"<<endl;}
};

class Sister:public Father
{
    public:
    void display1  ()override{cout<<"This is Sister"<<endl;}
    void display2  ()override{cout<<"This is Sister"<<endl;}
};


int main()
{
    Father f1obj;
    Son s1obj;
    Sister SS1obj;
    Father * p=new Son;
    void ** vtable1=*(void***)(&f1obj);
    void ** vtable2=*(void***)(&s1obj);
    void ** vtable3=*(void***)(&SS1obj);
    cout<<"这是Father类f1obj实例的虚函数表指针 "<<vtable1<<endl;
    cout<<"这是Son类f1obj实例的虚函数表指针 "<<vtable1<<endl;
    cout<<"这是Sister类f1obj实例的虚函数表指针 "<<vtable1<<endl;
    cout<<"从上述地址可以看出父类与继承类虚函数表的关系"<<endl;
    p->display1();
    cout<<"通过基类指针我们可以调用虚函数表中的内容"<<endl;
    return 0;
}































