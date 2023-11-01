#include <iostream>

using namespace std;
class Car {
public:
    Car(int year, double basePrice) : year(year), basePrice(basePrice) {}

    virtual double calculatePrice() const {
        return basePrice;
    }

    void displayInfo() const {
        cout << "Year: " << year << ", Base Price: $" << basePrice << ", Final Price: $" << calculatePrice() << endl;
    }
    protected:
    int year;
    double basePrice;
};

class sedan : public Car {
public:
    sedan(int year, double basePrice, double upgradPrice) : Car(year, basePrice), upgradPrice(upgradPrice){}

    double calculatePrice() const override {
        double sedanPrice = basePrice + (upgradPrice);
        return sedanPrice;
    }

private:
    double upgradPrice;
};

class SUV : public Car {
public:
    SUV(int year, double basePrice, double upgradPrice1, double upgradPrice2) : Car(year, basePrice), upgradPrice1(upgradPrice1), upgradPrice2(upgradPrice2) {}

    double calculatePrice() const override {
        double suvPrice = basePrice + (upgradPrice1) + (upgradPrice2);
        return suvPrice;
    }
private:
   double upgradPrice1;
   double upgradPrice2;
};

int main() {
    sedan sedan1(2023, 100000.0, 80000.0);
    SUV suv1(2023, 120000.0, 80000.0, 50000.0);

    sedan1.displayInfo();
    suv1.displayInfo();

    return 0;
}

