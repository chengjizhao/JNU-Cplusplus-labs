#include <iostream>
using namespace std;

class car {
 private:
  int engine, wheel, decorate, base;
  ;

 public:
  car(int e, int w, int d, int b) {
    engine = e;
    wheel = w;
    decorate = d;
    base = b;
  };
  int get_e() { return engine; };
  int get_w() { return wheel; }
  int get_d() { return decorate; }
  int get_b() { return base; }
  virtual void calculatePrice() {
    int tot;
    tot = engine + wheel + decorate;
    cout << "Car's price is " << tot;
  }
};

class sedan : public car {
 public:
  sedan(int e, int w, int d, int b) : car(e, w, d, b){};
  void calculatePrice() override {
    int tot;
    tot = get_d() + get_e() + get_w() + get_b();
    cout << "sedan's price is " << tot;
  }
};

class SUV : public car {
 public:
  SUV(int e, int w, int d, int b) : car(e, w, d, b){};
  void calculatePrice() override {
    int tot;
    tot = get_d() + get_e() + get_w() + get_b();
    cout << "SUV's price is " << tot;
  }
};

int main() {
  int e, w, d, b;
  cin >> e >> w >> d >> b;
  car* car1 = new sedan(e, w, d, b);
  cin >> e >> w >> d >> b;
  car* car2 = new SUV(e, w, d, b);

  car1->calculatePrice();
  cout << endl;
  car2->calculatePrice();

  return 0;
}