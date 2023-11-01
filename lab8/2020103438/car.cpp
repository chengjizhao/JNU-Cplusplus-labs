#include <iostream>
#include <string>
using namespace std;


class Car
{
protected:
    std::string brand;
    int year;

public:
    Car(const std::string &b, int y) : brand(b), year(y) {}

    virtual double calculatePrice() const = 0;
};

class Sedan : public Car
{
private:
    int numDoors;

public:
    Sedan(const std::string &b, int y, int doors) : Car(b, y), numDoors(doors) {}

    double calculatePrice() const override
    {
        return 30000 + numDoors * 1000;
    }
};

class SUV : public Car
{
private:
    bool hasThirdRow;

public:
    SUV(const std::string &b, int y, bool thirdRow) : Car(b, y), hasThirdRow(thirdRow) {}

    double calculatePrice() const override
    {
        if (hasThirdRow)
        {
            return 80000;
        }
        else
        {
            return 70000;
        }
    }
};

int main()
{
    Car *car1 = new Sedan("Ford", 2021, 4);
    Car *car2 = new SUV("Benz", 2022, false); // 通过改变true或者false改变SUV“Benz”的价格

    cout << "Car1 Price: $" << car1->calculatePrice() << endl;
    cout << "Car2 Price: $" << car2->calculatePrice() << endl;

    delete car1;
    delete car2;

    return 0;
}