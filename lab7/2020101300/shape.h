#pragma once
#ifndef Shape_h
#define Shape_h
#define PI 3.141;
class shape
{
public:
 shape(){}
 ~shape(){}  //具备多态特性的类的析构函数有必要声明为virtual函数
 virtual double getarea() { return -1; }  //虚函数 系统分辨成员对象的真实性 调用了各自的重载函数
};
class circle:public shape   //继承shape类
{
public:
 circle();
 double getarea();
 void show();
 void set(int a, int b, int c);
private:
 int x1;
 int y1;
 int r;
};
class rectangle:public shape
{
public:
 rectangle();
 double getarea();
 void show();
 void set(int a, int b);
private:
 int chang;
 int kuan;
};
class triangle:public shape
{
public:
 triangle();
 double getarea();
 void show();
 void set(int a, int b, int c, int d, int e, int f);
 private:
 int x31;
 int y31;
 int x32;
 int y32;
 int x33;
 int y33;
 double l1;
 double l2;
 double l3;
};
#endif // !Shape_h
#pragma once