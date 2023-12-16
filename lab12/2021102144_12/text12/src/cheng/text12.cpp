#include<iostream>
#include"text12.h"
using namespace std;
void circle::Shapecout()
{
  cout<<"this is a circle"<<endl;
}
void rectangle::Shapecout()
{
  cout<<"this is a rectangle"<<endl;
}
void redCircle::Drawcout()
{
  this->shape_->Shapecout();
  cout<<"read"<<endl;
}
void greenCircle::Drawcout()
{
  this->shape_->Shapecout();
  cout<<"green"<<endl;
}