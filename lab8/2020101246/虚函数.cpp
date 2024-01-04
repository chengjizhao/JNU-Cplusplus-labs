#include<iostream>
#include<string>
using namespace std;

class Basic
{   
    public:
    virtual int First()
    {
        cout<<"This is Basic First"<<endl;
        return 0 ;
    }


        virtual int Second()
    {
        cout<<"This is Basic Second"<<endl;
        return 0 ;
    }
    

};



class Exten:public Basic    
{
    public:
    int First ()override    {
        cout<<"This is Exten First"<<endl;
        return 0 ;
    }

    int Second()override
    {
        cout<<"This is Exten Second"<<endl;
        return 0 ;
    }

};


class Exten_t:public Basic    
{
    public:
    int First ()override    {
        cout<<"This is Exten_t First"<<endl;
        return 0 ;
    }

    int Second()override
    {
        cout<<"This is Exten_t Second"<<endl;
        return 0 ;
    }

};

int main()
{
    Basic a;
    Basic b;
    Exten I;
    Exten II;
    Exten_t III;
    void ** vtable1=*(void* **)(&a);//将a的地址视为指向void*指针的指针（强制转换）从而获得虚表的第一个地址
    void ** vtable2=*(void* **)(&b);
    cout<<vtable1<<":基类对象a虚函数表地址"<<endl;
    cout<<vtable2<<":基类对象b虚函数表地址"<<endl;
    if(vtable1==vtable2)
    {
        cout<<"不同对象使用同一张虚函数表"<<endl<<endl;
    }
    else
    {
        cout<<"不同对象使用不同虚函数表"<<endl;
    }

    //继承类与基类的虚函数地址
    int (Exten::*Firs)()=&Exten::First;
    int (Basic::*Fir)()=&Basic::First;
    cout<<"Exten成员函数Fir的地址"<< reinterpret_cast<void*>(I.*Firs)<<endl;
    cout<<"Basic成员函数Fir的地址"<< reinterpret_cast<void*>(a.*Fir)<<endl;

    //不同派生类函数对象是否使用同一张虚函数表
    void ** vtable3=*(void* **)(&I);
    void ** vtable4=*(void* **)(&II);
    cout<<vtable3<<":Exten对象a虚函数表地址"<<endl;
    cout<<vtable4<<":Exten_t对象b虚函数表地址"<<endl;
 



return 0;
}