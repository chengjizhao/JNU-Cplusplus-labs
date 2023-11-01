#include <iostream>

// ���� Car
class Car {
protected:
    double basePrice;  // �����۸�

public:
    Car(double price) : basePrice(price) {}

    virtual double calculatePrice() {
        return basePrice;
    }
};

// ������ Sedan
class Sedan : public Car {
public:
    Sedan(double price) : Car(price) {}

    double calculatePrice() override {
        // ���� Sedan ��ļ۸��ǻ����۸�� 1.5 ��
        return basePrice * 1.5;
    }
};

// ������ SUV
class SUV : public Car {
public:
    SUV(double price) : Car(price) {}

    double calculatePrice() override {
        // ���� SUV ��ļ۸��ǻ����۸�� 2 ��
        return basePrice * 2;
    }
};

int main() {
    Car* car1 = new Sedan(10000.0);
    Car* car2 = new SUV(20000.0);

    std::cout << "Sedan price: $" << car1->calculatePrice() << std::endl;
    std::cout << "SUV price: $" << car2->calculatePrice() << std::endl;

    delete car1;
    delete car2;

    return 0;
}