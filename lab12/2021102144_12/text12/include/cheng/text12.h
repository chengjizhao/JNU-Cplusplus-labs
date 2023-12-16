#pragma once
#include<iostream>
using namespace std;
class shape
{
  public:
  virtual void Shapecout()=0;
};
class circle:public shape
{
    public:
    virtual void Shapecout();
};
class rectangle:public shape
{
    public:
    virtual void Shapecout();
};
class drawAPI
{
    public:
    drawAPI(){}
    drawAPI(shape* a):shape_(a){}
    virtual void Drawcout()=0;
    protected:
    shape* shape_;
};
class redCircle:public drawAPI
{
    public:
    redCircle(){}
    redCircle(shape* a):drawAPI(a){}
    virtual void Drawcout();
};
class greenCircle:public drawAPI
{
    public:
    greenCircle(){}
    greenCircle(shape* a):drawAPI(a){}
    virtual void Drawcout();
};