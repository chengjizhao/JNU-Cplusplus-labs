#include <iostream>

class Car {
public:
    virtual double calculatePrice() const = 0;
};

class Sedan : public Car {
private:
    double basePrice;
    double additionalFeaturesPrice;

public:
    Sedan(double base, double additional) : basePrice(base), additionalFeaturesPrice(additional) {}

    double calculatePrice() const override {
        return basePrice + additionalFeaturesPrice;
    }
};

class SUV : public Car {
private:
    double basePrice;
    double offRoadPackagePrice;

public:
    SUV(double base, double offRoad) : basePrice(base), offRoadPackagePrice(offRoad) {}

    double calculatePrice() const override {
        return basePrice + offRoadPackagePrice;
    }
};

int main() {
    Car* car1 = new Sedan(20000.0, 1500.0);
    Car* car2 = new SUV(30000.0, 2000.0);

    std::cout << "Sedan price: $" << car1->calculatePrice() << std::endl;
    std::cout << "SUV price: $" << car2->calculatePrice() << std::endl;

    delete car1;
    delete car2;

    return 0;
}