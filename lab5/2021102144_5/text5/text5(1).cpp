#include"text5.h"
#include<iostream>
using namespace std;
Person::Person()//构造函数，创建对象时运行
{
    Id=0;
    cout<<"您创造了一个对象person"<<endl;
}
Person::Person(int a)
{
    cout<<"您创造了一个新对象person,编号为："<<a<<endl;
}
Person::Person(int a,int b)
{
    cout<<"您创造了一个新新对象person,编号为："<<a<<"也可以为："<<b<<endl;
}
Person::~Person()//析构函数，程序结束后运行
{
}
void Person::setId()
{
    cout<<"请输入你的Id"<<endl;
    cin>>Id;
}
void Person::getId()
{
   if(Id==0)
   cout<<"您还未输入Id"<<endl;
   else
   cout<<"您的Id为："<<Id<<endl;  
}
void Person::setBorn()
{
    cout<<"请输入你的出生年月日"<<endl;
    cin>>Born;
}
void Person::getBorn()
{
   cout<<"您的出生年月日为："<<Born<<endl;
}
void Person::setSex()
{
    cout<<"请输入你的性别（男输入1，女输入0）"<<endl;
    cin>>Sex;
}
void Person::getSex()
{
   if(Sex)
   {
   cout<<"您的性别为男"<<endl;
   }
   else
   {
   cout<<"您的性别为女"<<endl;
   }
}
void Person::setHigh()
{
    cout<<"请输入你的身高"<<endl;
    cin>>High;
}
void Person::getHigh()
{
   cout<<"您的身高为："<<High<<endl;
}
void Person::setWeight()
{
    cout<<"请输入你的体重"<<endl;
    cin>>Weight;
}
void Person::getWeight()
{
   cout<<"您的体重为："<<Weight<<endl;
}