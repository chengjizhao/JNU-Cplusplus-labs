#include <iostream>
using namespace std;

class shape {
 public:
  double area, cir;
  void ShowArea();
  void ShowCir();
};

class circle : public shape {
 private:
  double r;

 public:
  circle(double r1) { r = r1; }
  void circle_Are();
  void circle_Cir();
};

class rectangle : public shape {
 private:
  double a, b;

 public:
  rectangle(double &x, double &y) {
    a = x;
    b = y;
  }
  void rectangle_Are();
  void rectangle_Cir();
};

class triangle : public shape {
 private:
  double a, b, c;

 public:
  triangle(double &_a, double &_b, double &_c) {
    a = _a;
    b = _b;
    c = _c;
  }
  void triangle_Are();
  void triangle_Cir();
};