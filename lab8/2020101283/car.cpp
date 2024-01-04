#include <iostream>
using namespace std;

class Car {
public:
  virtual double calculatePrice() = 0;
};

class Sedan : public Car {
private:
  int seatCount;
public:
  Sedan(int seatCount):seatCount(seatCount) {}
  double calculatePrice() override {
    return 10000 + seatCount * 2000; 
  }
};

class SUV : public Car {  
private:
  int cargoVolume;
public:
  SUV(int cargoVolume):cargoVolume(cargoVolume) {}
  double calculatePrice() override {
    return 20000 + cargoVolume * 500;
  }
};

int main() {
  Sedan s1(4);
  SUV suv1(60);
  
  cout << s1.calculatePrice() << endl;
  cout << suv1.calculatePrice() << endl;

  return 0;
}
