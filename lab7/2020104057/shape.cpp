#include "shape.h"
#include <iostream>
#include <math.h>
using namespace std;

circle::circle()
{
  x1 = 0;
  y1 = 0;
  r = 0;
}

double circle::getarea()
{
  double s;
  s = PI;
  s = s * r * r;
  return s;
}

void circle::show()
{
  double c;
  c = PI;
  c = c * 2 * r;
  cout << "(" << x1 << "," << y1 << ")" << endl;//坐标；
  cout << "2R =" << 2 * r << endl;              //直径；
  cout << "circum =" << c << endl;              //周长；
}

void circle::set(int a, int b, int c)
{
  this->x1 = a;
  this->y1 = b;
  this->r = c;
}

rectangle::rectangle()
{
  chang = 0;
  kuan = 0;
}

double rectangle::getarea()
{
  int s;
  s = chang * kuan;
  return s;
}

void rectangle::show()
{
  cout << "chang = " << chang << endl;
  cout << "kuan = " << kuan << endl;
  cout << "rectangle circum = " << 2 * (chang + kuan) << endl;
}

void rectangle::set(int a, int b)
{
  chang = a;
  kuan = b;
}

triangle::triangle() 
{
  x31 = 0;
  y31 = 0;
  x32 = 0;
  y32 = 0;
  x33 = 0;
  y33 = 0;
  l1 = 0;
  l2 = 0;
  l3 = 0;
}

double triangle::getarea()
{
  double s;
  double p;
  p = (l1 + l2 + l3) / 2;
  s = p * (p - l1) * (p - l2) * (p - l3);
  s = sqrt(s);
  return s;
}


void triangle::set(int a, int b, int c, int d, int e, int f)
{
  x31 = a;
  y31 = b;
  x32 = c;
  y32 = d;
  x33 = e;
  y33 = f;
}

void triangle::show()
{
  cout << "location:\n(" << x31 << "," << y31 << ")" << endl;
  cout << "(" << x32 << "," << y32 << ")" << endl;
  cout << "(" << x33 << "," << y33 << ")" << endl;
  double a, b, c, c1;
  a = pow((x31 - x32), 2) + pow((y31 - y32), 2);
  a = sqrt(a);
  b = pow((x31 - x33), 2) + pow((y31 - y33), 2);
  b = sqrt(b);
  c = pow((x32 - x33), 2) + pow((y32 - y33), 2);
  c = sqrt(c);
  c1 = a + b + c;
  l1 = a;
  l2 = b;
  l3 = c;
  cout << "triangle circum = " << c1 << endl;
}

