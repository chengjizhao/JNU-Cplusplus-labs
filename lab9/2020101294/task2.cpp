#include <iostream>

// ���� Vehicle
class Vehicle {
protected:
    int speed;

public:
    Vehicle(int spd) : speed(spd) {}

    virtual void start() {
        std::cout << "Vehicle started." << std::endl;
    }
};

// ������ Car
class Car : virtual public Vehicle {
public:
    Car(int spd) : Vehicle(spd) {}

    void start() override {
        std::cout << "Car started. Speed: " << speed << " km/h." << std::endl;
    }
};

// ������ Boat
class Boat : virtual public Vehicle {
public:
    Boat(int spd) : Vehicle(spd) {}

    void start() override {
        std::cout << "Boat started. Speed: " << speed << " knots." << std::endl;
    }
};

// ������ AmphibiousVehicle ͬʱ�̳��� Car �� Boat
class AmphibiousVehicle : public Car, public Boat {
public:
    AmphibiousVehicle(int carSpeed, int boatSpeed) : Vehicle(carSpeed), Car(carSpeed), Boat(boatSpeed) {}

    // ʵ���麯�� start ��������μ̳�����
    void start() override {
        std::cout << "AmphibiousVehicle started. Car Speed: " << Car::speed << " km/h, Boat Speed: " << Boat::speed << " knots." << std::endl;
    }
};

int main() {
    AmphibiousVehicle amphibiousVehicle(60, 30);

    // ��ʾ���μ̳�����ͽ������
    amphibiousVehicle.start();

    return 0;
}