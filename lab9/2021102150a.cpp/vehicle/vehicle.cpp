#include <iostream>
using namespace std;

class vehicle {
 private:
  int speed, road;

 public:
  virtual void start() { cout << " speed is " << speed << endl; };
  void set_speed(int x) { speed = x; }
  int get_speed() { return speed; }
  int get_road() { return road; }
  vehicle(int x) : road(x), speed(0){};
};

class car : public virtual vehicle {
 public:
  car(int x) : vehicle(x) { set_speed(x * 100); }
  void start() {
    cout << "Car's speed ";
    if (get_road() == 1)
      cout << "on road ";
    else
      cout << "in waterway ";
    cout << "is " << get_speed() << endl;
  }
};

class boot : public virtual vehicle {
 public:
  boot(int x) : vehicle(!x) { set_speed((!x) * 60); }
  void start() {
    cout << "boot's speed ";
    if (get_road() == 1)
      cout << "on road ";
    else
      cout << "in waterway ";
    cout << "is " << get_speed() << endl;
  }
};

class AmphibiousVehicle : public car, public boot {
 public:
  AmphibiousVehicle(int x) : vehicle(x), car(x), boot(x) {
    if (x)
      set_speed(100);
    else
      set_speed(60);
  };
  void start() {
    cout << "AmphibiousVehicl's speed ";
    if (get_road() == 1)
      cout << "on road ";
    else
      cout << "in waterway ";
    cout << "is " << get_speed() << endl;
  }
};

int main() {
  AmphibiousVehicle Car1(1);
  Car1.start();
  AmphibiousVehicle Car2(0);
  Car2.start();
  return 0;
}