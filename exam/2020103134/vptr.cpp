#include<iostream>

class base{
    public:
    virtual void func1()=0;
};

class derive{
    public:
    void func1(){std::cout<<"重写虚函数fun1"<<endl;}
};

int main(){
    base* p;
    derive obj1;
    p=&obj1;
    p->func1();
    return 0;
}
//derive类继承了base的虚函数，并对base的虚函数进行重载，基类指针仍可以调用
