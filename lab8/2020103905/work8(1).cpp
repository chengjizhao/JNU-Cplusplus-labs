#include <iostream>

class Car {
protected:
    double price;

public:
    Car(double p) : price(p) {}

    virtual double calculatePrice() {
        return price;
    }
};

class Sedan : public Car {
public:
    Sedan(double p) : Car(p) {}

    double calculatePrice() override {
        // ���� Sedan ���͵���������۸���ض��߼�
        return price * 1.2; // ���� Sedan �ļ۸�Ȼ����۸��20%
    }
};

class SUV : public Car {
public:
    SUV(double p) : Car(p) {}

    double calculatePrice() override {
        // ���� SUV ���͵���������۸���ض��߼�
        return price * 1.5; // ���� SUV �ļ۸�Ȼ����۸��50%
    }
};

int main() {
    Car* car1 = new Sedan(10000.0);
    Car* car2 = new SUV(20000.0);

    std::cout << "Car 1 price: " << car1->calculatePrice() << std::endl;
    std::cout << "Car 2 price: " << car2->calculatePrice() << std::endl;

    delete car1;
    delete car2;

    return 0;
}