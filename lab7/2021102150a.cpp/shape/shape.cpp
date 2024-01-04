#include "shape.h"

#include <math.h>

#include <iostream>
static double pi = 3.14;

void shape::ShowArea() {
  cout << "面积为:" << area << endl;
  return;
}

void shape::ShowCir() {
  cout << "周长为:" << cir << endl;
  return;
}

void circle::circle_Are() {
  area = pi * r * r;
  ShowArea();
}

void circle::circle_Cir() {
  cir = 2 * pi * r;
  ShowCir();
}

void rectangle::rectangle_Are() {
  area = a * b;
  ShowArea();
}

void rectangle::rectangle_Cir() {
  cir = 2 * (a + b);
  ShowCir();
}

void triangle::triangle_Are() {
  double p = (a + b + c) / 2;
  area = p * sqrt(p * (p - a) * (p - b) * (p - c));
  ShowArea();
}

void triangle::triangle_Cir() {
  cir = a + b + c;
  ShowCir();
}