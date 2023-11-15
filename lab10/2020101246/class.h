#ifndef _CLASS_H_
#define _CLASS_H_
#include<iostream>
using namespace std;
class Classic
{
    public:
    int a;
    Classic(const int & x ):a(x){};
    Classic(){};
    ~Classic(){};
};

class ClassVIr
{
    public:
    int a;
    ClassVIr(){};
    ~ClassVIr(){};
    ClassVIr (const int & x){a=x;};
    virtual void show(){cout<<"this is ClassVir\n";}
};

class BClassVIr:public ClassVIr
{
    public:
    int b;
    BClassVIr(){};
    BClassVIr(const int & x,const int & y):ClassVIr(x),b(y){};
    ~BClassVIr(){};
    void show()override{cout<<"this is BClassVir";};
};
class  Bclassic:public Classic
{
    public:
    int b;
    Bclassic(const int & x,const int & y):Classic(x),b(y){};
    Bclassic(){};
    ~Bclassic(){};
};


class Basic
{
    public:
    int data;
    Basic(){};
    Basic(const int & x):data(x){};
    ~Basic(){};
    virtual void show(){};
};

class Father:public Basic
{
    public:
    Father(const int & x):Basic(x){};
    Father(){};
    ~Father(){};
    void show()override{cout<<data<<"this is Father virtual fun \t\n" ;}
};

class mother:public Basic
{
    public:
    mother(const int & x):Basic(x){};
    mother(){};
    ~mother(){};
     void show()override{cout<<data<<"this is mother virtual fun \t\n" ;}
};

class son:public Father,public mother
{
    public:
    int baby;
    son(){};
    son(const int & x,const int & y):Father(x),mother(x),baby(y){};
    //Basic(x)报错不允许间接使用非基类
    ~son(){};
    void show(){cout<<baby<<"this is son virtual fun \t\n" ;}
};

class BasicVir
{
    public:
    int data;
    BasicVir(){};
    BasicVir(const int & x):data(x){};
    ~BasicVir(){};
};

class FaVirr:virtual public BasicVir
{
    public:
    FaVirr(const int & x):BasicVir(x){};
    FaVirr(){};
    ~FaVirr(){};
    virtual void show(){cout<<data<<"this is FaVirr virtual fun \t\n" ;}
};

class MoVir:virtual public BasicVir
{
    public:
    MoVir(){};
    MoVir(const int & x):BasicVir(x){};
    ~MoVir(){};
    virtual void show(){cout<<data<<"this is MoVir virtual fun \t\n" ;}
};

class SonVir:public FaVirr,public MoVir
{
    public:
    int baby;
    SonVir(){};
    SonVir(const int & x,const int & y):FaVirr(x),MoVir(x),baby(y){};
    //BasicVir(x)报错不允许间接使用非基类
    ~SonVir(){};
    void show()override{cout<<baby<<"this is SonVir virtual fun \t\n" ;}
};






#endif