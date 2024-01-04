#include <iostream>

class Car 
{
  protected:
    double price;

  public:
    Car(double p) : price(p) {}

    virtual double calculatePrice() {
        return price;
    }
};

class Sedan : public Car 
{
  public:
    Sedan(double p) : Car(p) {}

    // 根据Sedan类型的汽车计算价格的特定逻辑，假设 Sedan 的价格为基础价格的120%
    double calculatePrice() override 
    {
      return price * 1.2; 
    }
};

class SUV : public Car 
{
  public:
    SUV(double p) : Car(p) {}

    // 根据SUV类型的汽车计算价格的特定逻辑，假设 SUV 的价格为基础价格的150%
    double calculatePrice() override 
    {      
    return price * 1.5; 
    }
};

int main() 
{
  Car* car1 = new Sedan(10000.00);
  Car* car2 = new SUV(20000.00);

  std::cout << "Car 1 price: " << car1->calculatePrice() << std::endl;
  std::cout << "Car 2 price: " << car2->calculatePrice() << std::endl;

  delete car1;
  delete car2;

  system("pause");
  return 0;

}
